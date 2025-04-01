# LeetCode Solutions

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT?) [![Total Problems](https://img.shields.io/badge/Total%20Solved-33-orange)](https://github.com/imReese/leetcode-solutions/tree/main/problems/) [![Languages](https://img.shields.io/badge/Languages-C++%20%7C%20Python-blue)](https://github.com/imReese/leetcode-solutions/tree/main/languages/)

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
- 🧮 **动态规划**: [Dynamic Programming](./tags/dynamic-programming.md)
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
| [1](https://leetcode.cn/problems/two-sum/) | 两数之和 | 简单 | `数组`、`哈希表` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0001-two-sum/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/0001-two-sum/solution.py) | 2025-03-26 |
| [7](https://leetcode.cn/problems/reverse-integer/) | 整数翻转 | 中等 | `数学` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0007-reverse-integer/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/0007-reverse-integer/solution.py) | 2025-02-22 |
| [15](https://leetcode.cn/problems/3sum/) | 三数之和 | 中等 | `数组`、`双指针`、`排序` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0015-3sum/solution.cpp) | 2025-02-25 |
| [18](https://leetcode.cn/problems/4sum/) | 四数之和 | 中等 | `数组`、`双指针`、`排序` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0018-4sum/solution.cpp) | 2025-02-25 |
| [27](https://leetcode.cn/problems/remove-element/) | 移除元素 | 简单 | `数组`、`双指针` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0027-remove-element/solution.cpp) | 2025-02-22 |
| [349](https://leetcode.cn/problems/intersection-of-two-arrays/) | 两个数组的交集 | 简单 | `数组`、`哈希表`、`双指针`、`二分查找`、`排序` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0349-intersection-of-two-arrays/solution.cpp) | 2025-03-29 |
| [624](https://leetcode.cn/problems/maximum-distance-in-arrays/) | 数组列表中的最大距离 | 中等 | `贪心`、`数组` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0624-maximum-distance-in-arrays/solution.cpp) | 2025-02-19 |
| [633](https://leetcode.cn/problems/sum-of-square-numbers/) | 平方数之和 | 中等 | `数学`、`双指针`、`二分查找` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0633-sum-of-square-numbers/solution.cpp) | 2025-03-31 |
| [888](https://leetcode.cn/problems/fair-candy-swap/) | 公平的糖果交换 | 简单 | `数组`、`哈希表`、`二分查找`、`排序` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0888-fair-candy-swap/solution.cpp) | 2025-02-22 |
| [914](https://leetcode.cn/problems/x-of-a-kind-in-a-deck-of-cards/) | 卡牌分组 | 简单 | `数组`、`哈希表`、`数学`、`计数`、`数论` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/0914-x-of-a-kind-in-a-deck-of-cards/solution.cpp) | 2025-02-22 |
| [1287](https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/) | 有序数组中出现次数超过25%的元素 | 简单 | `数组` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/1287-element-appearing-more-than-25-in-sorted-array/solution.cpp) | 2025-02-17 |
| [1299](https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/) | 将每个元素替换为右侧最大元素 | 简单 | `数组` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/1299-replace-elements-with-greatest-element-on-right-side/solution.cpp) | 2025-02-18 |
| [1706](https://leetcode.cn/problems/where-will-the-ball-fall/) | 球会落何处 | 中等 | `数组`、`矩阵`、`模拟` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/1706-where-will-the-ball-fall/solution.cpp) | 2025-02-15 |
| [1834](https://leetcode-cn.com/problems/single-threaded-cpu/) | 单线程 CPU | 中等 | `数组`、`排序`、`堆（优先队列）` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/1834-single-threaded-cpu/solution.cpp) | 2025-02-18 |
| [1963](https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/) | 使字符串平衡的最小交换次数 | 中等 | `栈`、`贪心`、`双指针`、`字符串` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/1963-minimum-number-of-swaps-to-make-the-string-balanced/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/1963-minimum-number-of-swaps-to-make-the-string-balanced/solution.py) | 2025-03-30 |
| [2080](https://www.leetcode.cn/problems/range-frequency-queries/) | 区间内查询数字的频率 | 中等 | `设计`、`线段树`、`数组`、`哈希表`、`二分查找` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2080-range-frequency-queries/solution.cpp) | 2025-02-18 |
| [2109](https://leetcode.cn/problems/adding-spaces-to-a-string/) | 向字符串添加空格 | 中等 | `数组`、`双指针`、`字符串`、`模拟` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2109-adding-spaces-to-a-string/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/2109-adding-spaces-to-a-string/solution.py) | 2025-03-30 |
| [2140](https://leetcode.cn/problems/solving-questions-with-brainpower/) | 解决智力问题 | 中等 | `数组`、`动态规划` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2140-solving-questions-with-brainpower/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/2140-solving-questions-with-brainpower/solution.py) | 2025-04-01 |
| [2209](https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/) | 用地毯覆盖后的最少白色砖块 | 困难 | `字符串`、`动态规划`、`前缀和` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2209-minimum-white-tiles-after-covering-with-carpets/solution.cpp) | 2025-02-21 |
| [2259](https://leetcode-cn.com/problems/remove-digit-from-number-to-maximize-result/) | 移除指定数字得到的最大结果 | 简单 | `贪心`、`字符串`、`枚举` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2259-remove-digit-from-number-to-maximize-result/solution.cpp) | 2025-02-18 |
| [2278](https://leetcode.cn/problems/percentage-of-letter-in-string/) | 字母在字符串中的百分比 | 简单 | `字符串` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2278-percentage-of-letter-in-string/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/2278-percentage-of-letter-in-string/solution.py) | 2025-03-31 |
| [2360](https://leetcode.cn/problems/longest-cycle-in-a-graph/) | 图中的最长环 | 困难 | `深度优先搜索`、`广度优先搜索`、`图`、`拓扑排序` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2360-longest-cycle-in-a-graph/solution.cpp) | 2025-03-29 |
| [2502](https://leetcode.cn/problems/design-memory-allocator/description/) | 设计内存分配器 | 中等 | `设计`、`数组`、`哈希表`、`模拟` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2502-design-memory-allocator/solution.cpp) | 2025-02-25 |
| [2506](https://leetcode.cn/problems/count-pairs-of-similar-strings/) | 统计相似字符串对的数目 | 简单 | `位运算`、`数组`、`哈希表`、`字符串`、`计数` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2506-count-pairs-of-similar-strings/solution.cpp) | 2025-02-22 |
| [2521](https://leetcode-cn.com/problems/distinct-prime-factors-of-product-of-array/) | 数组乘积中的不同质因数数目 | 中等 | `数组`、`哈希表`、`数学`、`数论` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2521-distinct-prime-factors-of-product-of-array/solution.cpp) | 2025-02-17 |
| [2595](https://leetcode.cn/problems/number-of-even-and-odd-bits/) | 奇偶位数 | 简单 | `位运算` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2595-number-of-even-and-odd-bits/solution.cpp) | 2025-02-20 |
| [2711](https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/) | 对角线上不同值的数量差 | 中等 | `数组`、`哈希表`、`矩阵` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2711-difference-of-number-of-distinct-values-on-diagonals/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/2711-difference-of-number-of-distinct-values-on-diagonals/solution.py) | 2025-03-28 |
| [2712](https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/) | 使所有字符相等的最小成本 | 中等 | `贪心`、`字符串`、`动态规划` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2712-minimum-cost-to-make-all-characters-equal/solution.cpp) [Python](https://github.com/imReese/leetcode-solutions/tree/main/problems/2712-minimum-cost-to-make-all-characters-equal/solution.py) | 2025-03-27 |
| [2716](https://leetcode.cn/problems/minimize-string-length/) | 最小化字符串长度 | 简单 | `哈希表`、`字符串` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2716-minimize-string-length/solution.cpp) | 2025-03-28 |
| [2829](https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/) | k-avoiding 数组的最小总和 | 中等 | `贪心`、`数学` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/2829-determine-the-minimum-sum-of-a-k-avoiding-array/solution.cpp) | 2025-03-26 |
| [3439](https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/) | 重新安排会议得到最多空余时间 I | 中等 | `贪心`、`数组`、`滑动窗口` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/3439-reschedule-meetings-for-maximum-free-time-i/solution.cpp) | 2025-02-20 |
| [3440](https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-ii/) | 重新安排会议得到最多空余时间 II | 中等 | `贪心`、`数组`、`枚举` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/3440-reschedule-meetings-for-maximum-free-time-ii/solution.cpp) | 2025-02-20 |
| [LCR 191](https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/) | 按规则计算统计结果 | 中等 | `数组`、`前缀和` | [C++](https://github.com/imReese/leetcode-solutions/tree/main/problems/LCR191-gou-jian-cheng-ji-shu-zu-lcof/solution.cpp) | 2025-02-18 |

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
    copy solution.cpp 或 copy solution.py ...
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
