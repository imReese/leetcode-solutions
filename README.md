# LeetCode Solutions

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT?) [![Total Problems](https://img.shields.io/badge/Total%20Solved-28-orange)](https://github.com/imReese/leetcode-solutions/tree/main/problems/) [![Languages](https://img.shields.io/badge/Languages-C++%20%7C%20Python-blue)](https://github.com/imReese/leetcode-solutions/tree/main/languages/)

---

## 统计中心

查看详细图表: [📈 刷题统计](./utils/statistics.md)

## 项目结构

```bash
leetcode-solutions/
├── README.md                  # 总目录&统计
├── problems/                  # 题解目录
│   ├── 0001-two-sum/          # 题目独立文件夹
│   │   ├── README.md          # 题目解析(思路/复杂度/示例)
│   │   ├── solution.cpp       # C++解法
│   │   ├── solution.py        # Python解法
│   │   └── testcases.txt      # 测试用例(可选)
│   ├── 0002-add-two-numbers/
│   │   └──...
│   └── ...   
├── tags/                      # 算法标签分类
│   ├── array.md               # 数组类题解索引
│   ├── linked-list.md         # 链表类题解索引
│   └── ...
├── utils/                     # 工具/统计
│   ├── statistics.md          # 刷题统计
│   └──...
└── LICENSE
```

## 标签导航

按算法类型快速定位:

- 🔍 **数组/双指针**: [Array](./tags/array.md)
- 🔗 **链表**: [Linked List](./tags/linked-list.md)
- 🌲 **树**: [Binary Tree](./tags/binary-tree.md)
- 🧮 **动态规划**: [Dynamic Programming](./tags/dp.md)
- ⏱️ **滑动窗口**: [Sliding Window](./tags/sliding-window.md)
- 🔍 **搜索**: [Search](./tags/search.md)
- 🧮 **数学**: [Math](./tags/math.md)
- 📚 **字符串**: [String](./tags/string.md)
- 🧩 **哈希表**: [Hash Table](./tags/hash-table.md)
- 🧩 **图**: [Graph](./tags/graph.md)
- 🧩 **位运算**: [Bit Manipulation](./tags/bit-manipulation.md)
- 🧩 **二分查找**: [Binary Search](./tags/binary-search.md)
- 🧩 **拓扑排序**: [Topological Sort](./tags/topological-sort.md)
- 🧩 **双指针**: [Two Pointers](./tags/two-pointers.md)
- 🧩 **矩阵**: [Matrix](./tags/matrix.md)
- 🧩 **排序**: [Sorting](./tags/sorting.md)

## 刷题进度表

| 题号 | 题目 | 难度 | 标签 | 解法 | 解题时间 |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [1](https://leetcode.cn/problems/two-sum/) | Two Sum | Easy | `数组`、`哈希表` | [C++](https://github.com/imReese/leetcode-solutions/blob/main/problems/0001-two-sum/solution.cpp), [Python](https://github.com/imReese/leetcode-solutions/blob/main/problems/0001-two-sum/solution.py) |
| [7](https://leetcode.cn/problems/reverse-integer/) | Reverse Integer | Meidum | `数学` | [C++](https://github.com/imReese/leetcode-solutions/blob/main/problems/0007-reverse-integer/solution.cpp), [Python](https://github.com/imReese/leetcode-solutions/blob/main/problems/0007-reverse-integer/solution.py) |
| [15](https://leetcode.cn/problems/3sum/) | 3Sum | Medium | `数组`, `双指针`, `排序` | [C++](https://github.com/imReese/leetcode-solutions/blob/main/problems/0015-3Sum/solution.cpp) |
| [18](https://leetcode-cn.com/problems/4sum/) | 4Sum | Medium | `数组`, `双指针`, `排序` | [C++](https://github.com/imReese/leetcode-solutions/blob/main/problems/0018-4Sum/solution.cpp) |
<!-- | [206](https://leetcode.cn/problems/reverse-linked-list/) | Reverse Linked List | Easy | `链表` | [C++](https://github.com/imReese/leetcode-solutions/blob/main/problems/0206-Reverse-Linked-List/solution.cpp) |
| [322](https://leetcode.cn/problems/coin-change/) | Coin Change | Medium | `动态规划` | [C++](https://github.com/imReese/leetcode-solutions/blob/main/problems/0322-Coin-Change/solution.cpp) |
|     |     |     |     |     | -->

## 使用说明

1. 查找题解

    ```bash
    # 按题号查找
    cd problems/0001-two-sum
    # 按标签查找
    open tags/array.md
    # 按语言查找
    open languages/cpp.md
    ```

2. 运行代码

    ```bash
    copy solution.cpp
    # 或
    copy solution.py
    到对应链接的leetcode网站运行
    ```

## 贡献指南

欢迎提交:

- 🐛 修正代码错误
- 🚀 新增高效解法
- 📝 补充题目解析

请遵循:

1. 新增题目时创建独立文件夹(格式: `题号-题目名`, 如: 0001-two-sum)
2. 在对应标签文档中添加索引
