import os
import re
from pathlib import Path
from collections import defaultdict

# =================配置区域=================
REPO_ROOT_DIR = Path(__file__).resolve().parent.parent
PROBLEMS_DIR = os.path.join(REPO_ROOT_DIR, "problems")
TAGS_DIR = os.path.join(REPO_ROOT_DIR, "tags")

README_FILE = os.path.join(REPO_ROOT_DIR, "README.md")
# TEMPLATE_PATH = os.path.join(REPO_ROOT_DIR, "utils/README_TEMPLATE.md")

# 支持的编程语言扩展名
LANG_EXTENSIONS = {
    ".py": "Python",
    ".java": "Java",
    ".cpp": "C++",
    ".js": "JavaScript",
    ".go": "Go"
}
# ==========================================

def collect_problems_data():
    """遍历problems目录收集题目数据"""
    problems = []
    lang_counter = defaultdict(int)
    tag_counter = defaultdict(int)

    for problem_dir in sorted(os.listdir(PROBLEMS_DIR)):
        # 跳过非目录
        problem_path = os.path.join(PROBLEMS_DIR, problem_dir)
        if not os.path.isdir(problem_path):
            continue

        print(f"Processing problem_dir: {problem_dir}")
        # 解析题号、题目名称和难度
        parts = problem_dir.split("-")
        number = parts[0]
        title = " ".join(parts[1:-1])
        difficulty = parts[-1].capitalize()

        # 获取解法文件
        solutions = []
        for f in os.listdir(problem_path):
            ext = os.path.splitext(f)[1]
            if ext in LANG_EXTENSIONS:
                lang = LANG_EXTENSIONS[ext]
                solutions.append({
                    "lang": lang,
                    "path": os.path.join("problems", problem_dir, f)
                })
                lang_counter[lang] += 1

        # 从README中提取标签
        tags = []
        readme_file = os.path.join(problem_path, "README.md")
        if os.path.exists(readme_file):
            with open(readme_file, "r", encoding="utf-8") as f:
                content = f.read()
                tag_section = re.search(r"## Tags\s*\n(.*?)\n\n", content, re.DOTALL)
                if tag_section:
                    tags = [t.strip() for t in tag_section.group(1).split("|") if t.strip()]

        # 合并数据
        problems.append({
            "number": number,
            "title": title,
            "difficulty": difficulty,
            "solutions": solutions,
            "tags": tags,
            "dir": problem_dir
        })

        # 统计标签
        for tag in tags:
            tag_counter[tag] += 1

    return sorted(problems, key=lambda x: int(x["number"])), lang_counter, tag_counter

def generate_problems_table(problems):
    """生成Markdown格式的题目表格"""
    table = [
        "| 题号 | 题目 | 难度 | 标签 | 解法 |",
        "|------|------|------|------|------|"
    ]
    
    for p in problems:
        leetcode_url = f"https://leetcode.com/problems/{p['title'].lower().replace(' ', '-')}/"
        solution_links = []
        for sol in p["solutions"]:
            solution_links.append(f"[{sol['lang']}]({sol['path']})")
        
        tags = " ".join([f"`{t}`" for t in p["tags"]])
        solutions = " ".join(solution_links)
        
        row = (
            f"| [{p['number']}]({leetcode_url}) | "
            f"{p['title']} | "
            f"{p['difficulty']} | "
            f"{tags} | "
            f"{solutions} |"
        )
        table.append(row)
    
    return "\n".join(table)

def generate_tag_navigation(tag_counter):
    """生成标签导航部分"""
    nav = []
    for tag, count in sorted(tag_counter.items()):
        tag_file = os.path.join("tags", f"{tag.lower().replace(' ', '-')}.md")
        nav.append(f"- 🏷️ **{tag}** ({count}题): [{tag}]({tag_file})")
    return "\n".join(nav)

def generate_badge_urls(total, lang_counter):
    """生成徽章URL"""
    badges = [
        f"[![Total Problems](https://img.shields.io/badge/Total%20Solved-{total}-blue)]({PROBLEMS_DIR})"
    ]
    
    lang_text = "%20%7C%20".join([f"{k}-{v}" for k, v in lang_counter.items()])
    badges.append(
        f"[![Languages](https://img.shields.io/badge/Languages-{lang_text}-orange)]()"
    )
    
    return "\n".join(badges)

def main():
    # 收集数据
    problems, lang_counter, tag_counter = collect_problems_data()
    total_problems = len(problems)

    # # 生成各部分内容
    # badges = generate_badge_urls(total_problems, lang_counter)
    # problem_table = generate_problems_table(problems)
    # tag_nav = generate_tag_navigation(tag_counter)
    
    # # 读取模板文件
    # with open(TEMPLATE_PATH, "r", encoding="utf-8") as f:
    #     template = f.read()
    
    # # 替换占位符
    # readme_content = template.replace("<!-- BADGES -->", badges)
    # readme_content = readme_content.replace("<!-- PROBLEM_TABLE -->", problem_table)
    # readme_content = readme_content.replace("<!-- TAG_NAVIGATION -->", tag_nav)
    
    # # 写入README
    # with open(README_PATH, "w", encoding="utf-8") as f:
    #     f.write(readme_content)

if __name__ == "__main__":
    print("Generating README.md...")
    main()