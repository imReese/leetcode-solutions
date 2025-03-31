# 2278. 字母在字符串中的百分比 (Percentage of Letter in String)

[LeetCode 原题链接](https://leetcode.cn/problems/percentage-of-letter-in-string/) | 难度: **简单** | 标签: `字符串`

## 题目描述

给你一个字符串 s 和一个字符 letter, 返回在 s 中等于 letter 字符所占的 百分比, 向下取整到最接近的百分比.

示例:

```plaintext
输入: s = "foobar", letter = "o"
输出: 33
解释:
等于字母 'o' 的字符在 s 中占到的百分比是 2 / 6 * 100% = 33%, 向下取整，所以返回 33 .
```

## 解法思路

### 遍历统计

- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int percentageLetter(string s, char letter) {
            int cnt = 0;
            for (char ch : s) {
                if (ch == letter) {
                    cnt++;
                }
            }
            return (100 * cnt / s.size());
        }
};
```

## 相似题目

- [451. 根据字符出现频率排序](https://leetcode.cn/problems/sort-characters-by-frequency/)

## Tags

[字符串](/tags/string.md)
