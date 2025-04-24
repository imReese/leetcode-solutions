import re
from collections import defaultdict
from datetime import datetime
from pathlib import Path
from urllib.parse import quote

# =================配置区域=================

USER_NAME = "imReese"
REPO_NAME = "leetcode-solutions"

REPO_ROOT_DIR = Path(__file__).resolve().parent.parent
PROBLEMS_DIR = REPO_ROOT_DIR / "problems"
TAGS_DIR = REPO_ROOT_DIR / "tags"
README_FILE = REPO_ROOT_DIR / "README.md"

# 支持的编程语言扩展名
LANG_EXTENSIONS = {
    ".cpp": "C++",
    ".py": "Python",
    ".go": "Go",
    ".sh": "Shell",
    ".java": "Java",
    ".js": "JavaScript",
}

# 语言注释前缀映射表（支持扩展）
COMMENT_PREFIXES = {
    ".cpp": ("//", "/*", "*/"),    # C++
    ".py": ("#", '"""', '"""'),    # Python
    ".go": ("//", "/*", "*/"),     # Go
    ".sh": ("#", "#", "#"),        # Shell
    ".swift": ("//", "/*", "*/"),  # Swift
    ".java": ("//", "/*", "*/"),   # Java
    ".js": ("//", "/*", "*/"),     # JavaScript
}

# ==========================================

def has_solution_files(dir_path: Path) -> bool:
    """ 判断题目目录下是否有解文件 """
    for ext in LANG_EXTENSIONS:
        if (dir_path / f"solution{ext}").exists():
            return True

def is_valid_problem_dir(dir_path: Path) -> bool:
    """ 判断是否为有效的题目目录 """
    return (
        dir_path.is_dir() and
        has_solution_files(dir_path)
    )

def natural_sort_key(path: Path):
    """ 自然排序的辅助函数 """
    name = path.name
    return [int(s) if s.isdigit() else s.lower() for s in re.split(r'(\d+)', name)]

def parse_problem_readme(readme_path: Path) -> dict:
    """ 解析题目 README.md 文件 """
    data = {
        "number": "",
        "title_zh": "",
        "title_en": "",
        "difficulty": "",
        "tags": [],
        "link": ""
    }
    with open(readme_path, "r", encoding="utf-8") as f:
        # 按行读取处理
        header_parsed = False
        for line in f:
            line = line.strip()

            # 解析标题行（仅处理第一个#开头的行）
            if not header_parsed and line.startswith("# "):
                title_pattern = re.compile(
                    r'^#\s*([A-Za-z]*\s\d+)\.?\s*'  # 题号
                    r'(.+?)\s*'                     # 中文标题
                    r'\((.+?)\)\s*$',               # 英文标题
                )
                if match := title_pattern.search(line):
                    data["number"] = match.group(1).strip()
                    data["title_zh"] = match.group(2).strip()
                    data["title_en"] = match.group(3).strip()
                header_parsed = True
                continue

            # 解析难度
            if "难度" in line and not data["difficulty"]:
                if match := re.search(r"难度[:：]\s*\*\*(\S+)\*\*", line):
                    data["difficulty"] = match.group(1)

            # 解析标签
            if "标签" in line and not data["tags"]:
                if match := re.search(r"标签[:：]\s*((`[^`]+`\s*[、]?\s*)+)", line):
                    data["tags"] = re.findall(r'`\s*([^`]+?)\s*`', match.group(1))

            # 解析原题链接
            if "原题链接" in line and not data["link"]:
                if match := re.search(r"\((https?://[^\s)]+)\)", line):
                    data["link"] = match.group(1)

            # 提前终止：主要元数据通常在文件头部
            if all(data.values()):
                break

    return data

def find_solutions(dir_path: Path) -> list:
    """ 查找题目下的所有解文件 """
    return [f.suffix for f in dir_path.glob("solution.*")
            if f.suffix in LANG_EXTENSIONS]

def get_solution_dates(dir_path: Path) -> list:
    """ 从solution文件提取时间 """
    dates = []
    for sol_file in dir_path.glob("solution.*"):
        ext = sol_file.suffix.lower()
        try:
            comment_config = COMMENT_PREFIXES.get(ext, ("//",))
            line_comment = comment_config[0]

            pattern = re.compile(
                fr'^{re.escape(line_comment)}\s*Date:\s*(\d{{4}}-\d{{2}}-\d{{2}})', 
                re.IGNORECASE
            )

            with open(sol_file, "r", encoding="utf-8") as f:
                for line in f:
                    if match := pattern.search(line.strip()):
                        try:
                            dates.append(datetime.strptime(match.group(1), "%Y-%m-%d"))
                            break
                        except ValueError as e:
                            print(f"文件 {sol_file.name} 日期格式错误: {e}")
                        except Exception as e:
                            print(f"意外错误: {str(e)}")
        except KeyError:
            print(f"未配置 {ext} 文件的注释符号, 已跳过")
        except UnicodeDecodeError:
            print(f"文件解码失败: {sol_file} (请检查编码)")
    return dates
    
def parse_problme_data(dir_path: Path) -> dict:
    """ 解析题目数据 """
    try:
        readme_data = parse_problem_readme(dir_path / "README.md")

        solution_files = find_solutions(dir_path)
        solution_dates = get_solution_dates(dir_path)

        return {
            "dir": dir_path.name,
            "number": readme_data.get("number"),
            "title_zh": readme_data.get("title_zh"),
            "title_en": readme_data.get("title_en"),
            "difficulty": readme_data.get("difficulty", "未知"),
            "tags": readme_data.get("tags", []),
            "solutions": solution_files,
            "solve_date": min(solution_dates) if solution_dates else "",
            "link": readme_data.get("link")
        }
    except Exception as e:
        print(f"解析失败 {dir_path}: {str(e)}")
        return None

def format_table_row(data: dict) -> str:
    """ 格式化表格行 """
    # 题目列
    title = f"{data['title_zh']}"

    # 解法链接
    base_url = f"https://github.com/{USER_NAME}/{REPO_NAME}/tree/main/problems/{data["dir"]}"
    solution_links = []
    for ext in data["solutions"]:
        normalized_ext = f".{ext.lstrip('.')}"
        if normalized_ext in LANG_EXTENSIONS:
            lang = LANG_EXTENSIONS[normalized_ext]
            file_ext = normalized_ext.lstrip('.')
            solution_links.append(
                f"[{lang}]({base_url}/solution.{file_ext})"    
            )
    solution_links.sort(key=lambda x: list(LANG_EXTENSIONS.values()).index(x[1:x.find(']')]))

    # 时间格式化
    date_str = data["solve_date"].strftime("%Y-%m-%d") if data["solve_date"] else "未记录"

    return (
        f"| [{data['number']}]({data['link']}) "
        f"| {title} "
        f"| {data['difficulty']} "
        f"| {'、'.join(f'`{tag}`' for tag in data['tags'])} "
        f"| {' '.join(solution_links)} "
        f"| {date_str} |"
    )

def generate_progress_table():
    """ 生成刷题进度表 """

    table = [
        "| 题号 | 题目 | 难度 | 标签 | 解法 | 解题时间 |\n"
        "| ----- | ----- | ----- | ----- | ----- | ----- |"
    ]

    for dir_path in sorted(PROBLEMS_DIR.iterdir(), key=natural_sort_key):
        if not is_valid_problem_dir(dir_path):
            continue

        # 收集题目数据
        problem_data = parse_problme_data(dir_path)
        if problem_data:
            table.append(format_table_row(problem_data))

    return "\n".join(table) + '\n'

def update_readme_badges(total_solved: int):
    """ 更新 README.md 中的刷题进度徽章 """
    with open(README_FILE, "r+", encoding="utf-8") as f:
        content = f.read()

        # 替换刷题进度徽章
        content = re.sub(
            r"(Total%20Solved-)(\d+)(-orange)",
            fr"\g<1>{total_solved}\g<3>",
            content
        )

        f.seek(0)
        f.write(content)
        f.truncate()

def update_readme_table(new_table: str):
    """ 更新 README.md 中的进度表 """
    with open(README_FILE, "r+", encoding="utf-8") as f:
        content = f.read()

        # 使用正则替换进度表
        updated = re.sub(
            r"(## 刷题进度表\n\n)(.*?)(\n## |$)",
            r"\g<1>" + new_table + r"\g<3>",
            content,
            flags=re.DOTALL
        )

        # 回写文件
        f.seek(0)
        f.write(updated)
        f.truncate()

def main():
    print("正在更新刷题进度...")

    # 生成完整进度表
    progress_table = generate_progress_table()

    # 计算总解决数
    solved_dirs = [d for d in PROBLEMS_DIR.iterdir() if is_valid_problem_dir(d)]
    total_solved = len(solved_dirs)

    # 执行更新
    update_readme_badges(total_solved)
    update_readme_table(progress_table)

if __name__ == "__main__":
    main()
