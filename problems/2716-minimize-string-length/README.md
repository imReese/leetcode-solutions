# 2716. 最小化字符串长度 (Minimize String Length)

[LeetCode 原题链接](https://leetcode.cn/problems/minimize-string-length/) | 难度: **简单** | 标签: `哈希表`、`字符串`

## 题目描述

给你一个下标从 0 开始的字符串 s , 重复执行下述操作 任意 次:

在字符串中选出一个下标 i , 并使 c 为字符串下标 i 处的字符. 并在 i 左侧（如果有）和 右侧（如果有）各 删除 一个距离 i 最近 的字符 c.
请你通过执行上述操作任意次, 使 s 的长度 最小化.

返回一个表示 最小化 字符串的长度的整数.

示例:

```plaintext
输入: s = "aaabc"
输出: 3
解释: 在这个示例中, s 等于 "aaabc" . 我们可以选择位于下标 1 处的字符 'a' 开始. 接着删除下标 1 左侧最近的那个 'a'（位于下标 0）以及下标 1 右侧最近的那个 'a'（位于下标 2）. 执行操作后, 字符串变为 "abc" . 继续对字符串执行任何操作都不会改变其长度. 因此, 最小化字符串的长度是 3 .
```

## 解法思路

### 哈希表

- 核心思想: 本题就是求字符串中不同字符的个数, 用一个哈希表记录不同字符的个数即可.
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int minimizedStringLength(string s) {
            int res = 0;
            unordered_set<char> set;
            for (char c : s) {
                if (set.find(c) == set.end()) {
                    set.insert(c);
                    res++;
                }
            }
            return res;
        }
};
```

## 相似题目

- [1047. 删除字符串中的所有相邻重复项](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)

## Tags

[哈希表](/tags/hash-table.md) | [字符串](/tags/string.md)
