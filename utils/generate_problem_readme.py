#!/usr/bin python3

import argparse
import json
import html2text
import re
import requests
from bs4 import BeautifulSoup
from functools import lru_cache
from html import unescape
from pathlib import Path
from tenacity import retry, stop_after_attempt, wait_exponential
from typing import Dict, Optional, Any

LANGUAGE_MAP = {
    "cpp": "cpp",
    "py": "python",
    "java": "java"
}

SUPPORTED_EXTENSIONS = {  # 支持检测的代码文件
    "cpp": ("//", "/*", "*/"),
    "py": ("#", '"""', '"""'),
}

# 难度转换
DIFFICULTY_MAP = {
    "Easy": "简单",
    "Medium": "中等", 
    "Hard": "困难"
}

DEFAULT_EXTENSION = "cpp"  # 默认检测的代码文件类型

def parse_code_metadata(file_path: Path) -> Dict[str, str]:
    """ 解析solution文件中的题目元数据 """
    metadata = {}
    solution_code = []

    # 根据文件类型获取注释配置
    ext = file_path.suffix[1:]
    comment_confg = SUPPORTED_EXTENSIONS.get(ext, ("//", "/*", "*/"))
    single_line_comment = comment_confg[0]
    multi_line_comment_start = comment_confg[1] if len(comment_confg) > 1 else None
    multi_line_comment_end = comment_confg[2] if len(comment_confg) > 2 else None
    
    in_multiline_comment = False # 多行注释状态跟踪
    metadata_section_end = False # 元数据结束标志

    # 读取文件内容
    with open(file_path, "r", encoding="utf-8") as f:
        for line in f:
            stripped_line = line.strip()
            raw_line = line.rstrip('\n')

            # 处理多行注释
            if multi_line_comment_start and multi_line_comment_end:
                if in_multiline_comment:
                    if multi_line_comment_end in stripped_line:
                        in_multiline_comment = False
                        end_pos = stripped_line.find(multi_line_comment_end) + len(multi_line_comment_end)
                        code_part = stripped_line[end_pos:].strip()
                        if code_part:
                            solution_code.append(code_part)
                    continue

                # 检测多行注释开始
                if not metadata_section_end and multi_line_comment_start in stripped_line:
                    in_multiline_comment = True
                    if multi_line_comment_end in stripped_line:
                        in_multiline_comment = False
                    continue
            
            if not metadata_section_end:
                if stripped_line.startswith(single_line_comment):
                    pattern = re.compile(
                        r'^\s*{prefix}\s*(\w+):\s*(.+?)\s*$'.format(
                            prefix=re.escape(single_line_comment)
                        ),
                        flags=re.IGNORECASE
                    )
                    if match := pattern.search(line):
                        key = match.group(1).lower()
                        value = match.group(2).strip()
                        metadata[key] = value
                        continue
                    continue
                else:
                    # 遇到第一个非注释行 结束元数据区
                    metadata_section_end = True

            # 处理代码行
            if not in_multiline_comment and metadata_section_end:
                code_line = re.sub(
                    r'\s*{prefix}.*$'.format(prefix=re.escape(single_line_comment)),
                    '',
                    raw_line
                )
                if code_line.strip():
                    solution_code.append(code_line)
        metadata["code"] = "\n".join(solution_code)

        metadata["language"] = LANGUAGE_MAP.get(ext, DEFAULT_EXTENSION)

    return metadata

@lru_cache(maxsize=100)
@retry(stop=stop_after_attempt(3), wait=wait_exponential(multiplier=1, min=4, max=10))
def get_leetcode_info(problem_url: str) -> Dict[str, Any]:
    """从LeetCode页面解析标准化题目信息
    
    Args:
        problem_url: LeetCode题目URL(支持中文站和国际站)
        
    Returns:
        包含标准化字段的字典结构：
        {
            "problem_id": "1",              # 题目ID
            "title_zh": "两数之和",           # 中文标题
            "title_en": "Two Sum",            # 英文标题
            "difficulty": "简单",             # 难度(自动转换中文)
            "tags_zh": ["数组", "哈希表"],    # 中文标签列表
            "tags_en": ["Array", ...],        # 英文标签列表
            "content_zh": "题目描述...",      # 中文题目描述(HTML格式)
            "code_snippets": [                # 代码片段列表
                {
                    "lang": "Python3",
                    "code": "class Solution: ..."
                }
            ]
        }
    """
    problem_info = {
        "problem_id": "",
        "title_zh": "",
        "title_en": "",
        "difficulty": "未知",
        "tags_zh": [],
        "tags_en": [],
        "content_zh": "",
        "code_snippets": []
    }

    try:
        # 添加浏览器标头模拟正常访问
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                          "AppleWebKit/537.36 (KHTML, like Gecko) "
                          "Chrome/119.0.0.0 Safari/537.36",
            "Accept-Language": "zh-CN,zh;q=0.9"
        }

        # 发送HTTP请求(添加超时和重试机制)
        response = requests.get(problem_url, headers=headers, timeout=15)
        response.raise_for_status()  # 检测HTTP错误
        
        # 解析HTML
        soup = BeautifulSoup(response.text, 'html.parser')
        script_data = soup.find('script', id='__NEXT_DATA__', type='application/json')
        if not script_data:
            raise ValueError("未找到NEXT_DATA脚本标签")

        # 解析JSON数据
        json_data = json.loads(script_data.string)

        queries = json_data['props']['pageProps']['dehydratedState']['queries']
        problem_data = None
        for query in queries:
            try:
                if "question" in query["state"]["data"]:
                    problem_data = query["state"]["data"]["question"]
                    break
            except (KeyError, TypeError):
                continue
        
        if not problem_data:
            raise ValueError("未找到题目数据")

        # 核心字段提取
        problem_info.update({
            "problem_id": str(problem_data.get("questionFrontendId", "")),
            "title_zh": problem_data.get("translatedTitle", ""),
            "title_en": problem_data.get("questionTitle", ""),
            "difficulty": DIFFICULTY_MAP.get(
                problem_data.get("difficulty", ""), 
                "未知"
            ),
            "tags_zh": [tag["translatedName"] for tag in problem_data.get("topicTags", [])],
            "tags_en": [tag["name"] for tag in problem_data.get("topicTags", [])],
            "content_zh": re.sub(r'\n{2,}', '\n\n', process_leetcode_specific(html_to_md(problem_data.get("translatedContent", "")))).strip() + '\n\n',
        })

        return problem_info

    except requests.RequestException as e:
        print(f"网络请求失败: {str(e)}")
    except json.JSONDecodeError:
        print("JSON解析失败，响应内容可能已变更")
    except Exception as e:
        print(f"数据处理异常: {str(e)}")
        
    return problem_info

def html_to_md(html: str) -> str:
    """将LeetCode的HTML题目描述转换为Markdown格式"""
    
    # 初始化转换器
    h = html2text.HTML2Text()
    h.ignore_links = False       # 保留链接
    h.ignore_images = False      # 保留图片
    h.body_width = 0             # 禁用自动换行
    h.mark_code = True           # 保留代码标记
    
    # 基础转换
    md = h.handle(html)
    
    # ===== 后处理优化 =====
    # 1. 清理多余空行
    md = re.sub(r'\n{3,}', '\n\n', md)
    
    # 2. 处理LeetCode特定示例块
    md = re.sub(
        r'【示例 (\d+)】：?', 
        r'**示例 \1**\n\n```text\n', 
        md
    )
    
    # 3. 转换HTML实体
    md = unescape(md)
    
    # 4. 标准化代码块
    md = re.sub(
        r'```\s*(\w+)?\n', 
        lambda m: f'```{m.group(1) or ""}\n', 
        md
    )
    
    return md.strip()

def process_leetcode_specific(md: str) -> str:
    """处理LeetCode特有结构"""
    
    # 处理输入输出示例
    md = re.sub(
        r'输入：(.*?)\n输出：(.*?)(\n|$)',
        r'输入：\n```\1\n```\n输出：\n```\2\n```\n',
        md,
        flags=re.DOTALL
    )
    
    # 处理提示信息
    md = re.sub(
        r'<button[^>]*>提示</button>',
        '\n**提示**\n',
        md
    )
    
    # 处理图片相对路径
    md = md.replace(
        '](//', 
        '](https://'
    )
    
    return md

def enrich_metadata(metadata: Dict[str, Any]) -> Dict[str, Any]:
    """通过LeetCode API丰富元数据(支持全量缓存)"""
    if "link" not in metadata:
        return metadata

    cache_file = Path(".leetcode_cache.json")
    cache = load_cache(cache_file)

    # 尝试从缓存读取完整数据
    if metadata["link"] in cache:
        print(f"使用缓存数据: {metadata['link']}")
        return merge_metadata(metadata, cache[metadata["link"]])

    # 请求完整题目数据
    problem_info = get_leetcode_info(metadata["link"])
    if not problem_info:
        return metadata

    # 标准化数据格式
    processed_data = {
        "problem_id": problem_info.get("problem_id", ""),
        "title_zh": problem_info.get("title_zh", ""),
        "title_en": problem_info.get("title_en", ""),
        "difficulty": problem_info.get("difficulty", "未知"),
        "tags": problem_info.get("tags_zh", []),
        "description": problem_info.get("content_zh", ""),
        "code": find_relevant_code(problem_info.get("code_snippets", []), metadata.get("lang"))
    }

    # 更新缓存
    cache[metadata["link"]] = processed_data
    # save_cache(cache_file, cache)

    return merge_metadata(metadata, processed_data)

def merge_metadata(original: Dict, new_data: Dict) -> Dict:
    """合并元数据(优先保留original数据)"""
    merged = original.copy()
    for k, v in new_data.items():
        if k not in merged or not merged[k]:  # 仅填充空白字段
            merged[k] = v
    return merged

def find_relevant_code(snippets: list, target_lang: str = None) -> str:
    """寻找最匹配的代码片段"""
    lang_priority = ["cpp", "python3", "java"]  # 默认优先级
    if target_lang:
        lang_priority.insert(0, target_lang.lower())

    for lang in lang_priority:
        for snippet in snippets:
            if snippet["langSlug"] == lang:
                return snippet["code"]
    return ""

def load_cache(cache_file: Path) -> Dict:
    """加载缓存文件"""
    try:
        if cache_file.exists():
            with open(cache_file, "r", encoding="utf-8") as f:
                return json.load(f)
        return {}
    except Exception as e:
        print(f"缓存加载失败: {str(e)}")
        return {}

def save_cache(cache_file: Path, data: Dict):
    """保存缓存文件"""
    try:
        with open(cache_file, "w", encoding="utf-8") as f:
            json.dump(data, f, ensure_ascii=False, indent=2)
    except Exception as e:
        print(f"缓存保存失败: {str(e)}")

def generate_readme_content(metadata: Dict) -> str:
    """生成完整README内容"""
    # 标题部分
    title_line = ""
    if metadata.get("title_zh") and metadata.get("title_en"):
        title_line = f"# {metadata['problem_id']}. {metadata['title_zh']} ({metadata['title_en']})\n\n"
    elif metadata.get("title_zh"):
        title_line = f"# {metadata['problem_id']}. {metadata['title_zh']}\n\n"
    elif metadata.get("title_en"):
        title_line = f"# {metadata['problem_id']}. {metadata['title_en']}\n\n"

    # 元信息行
    meta_line = []
    if metadata.get("link"):
        meta_line.append(f"[LeetCode 原题链接]({metadata['link']})")
    if metadata.get("difficulty"):
        meta_line.append(f"难度: **{metadata['difficulty']}**")
    if metadata.get("tags"):
        tags = "、".join(f"`{tag}`" for tag in metadata["tags"])
        meta_line.append(f"标签: {tags}")
    meta_section = " | ".join(meta_line) + "\n\n" if meta_line else ""

    # 描述部分
    desc_section = "## 题目描述\n\n" + metadata.get("description", "(题目描述待补充)\n\n")

    # 题解部分
    code_section = ""
    if metadata.get("code"):
        lang = metadata.get("language", "")
        code_section = f"## 解法思路\n\n```{lang}\n{metadata['code']}\n```\n"

    # 相似题目
    similar_section = ""
    if metadata.get("similar_problems"):
        similar_section = "## 相似题目\n\n"
        for problem in metadata["similar_problems"]:
            similar_section += f"- [{problem['title']}]({problem['link']})\n"

    # 合并所有部分
    return title_line + meta_section + desc_section + code_section

def main():
    parser = argparse.ArgumentParser(description="生成Leetcode题目README文档")
    parser.add_argument("-p", "--problem", type=str, required=True, help="问题目录路径(Example: problems/0001-two-sum")
    args = parser.parse_args()

    # 路径验证
    problem_dir = Path(args.problem).resolve()
    if not problem_dir.exists():
        raise FileNotFoundError(f"目录不存在: {problem_dir}")
    if not problem_dir.is_dir():
        raise NotADirectoryError(f"路径不是目录: {problem_dir}")

    # 检查是否包含README.md文件
    readme_file = problem_dir / "README.md"
    if readme_file.exists():
        raise FileExistsError(f"README.md文件已存在: {readme_file}")

    # 检查是否包含solution文件
    solution_file = None
    for ext in SUPPORTED_EXTENSIONS:
        candidate = problem_dir / f"solution.{ext}"
        if candidate.exists():
            solution_file = candidate
            break

    if not solution_file:
        raise FileNotFoundError(f"未找到solution file, 支持的类型：{', '.join(SUPPORTED_EXTENSIONS.keys())}")

    # 处理元数据
    metadata = parse_code_metadata(solution_file)

    # 补充信息
    metadata = enrich_metadata(metadata)

    # 生成README内容
    readme_content = generate_readme_content(metadata)

    # 写入文件
    readme_path = problem_dir / "README.md"
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(readme_content)

    print(f"成功生成：{readme_path}")

if __name__ == "__main__":
    main()