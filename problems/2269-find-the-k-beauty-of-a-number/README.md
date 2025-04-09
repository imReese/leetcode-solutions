# 2269. 找到一个数字的 K 美丽值 (Find the K-Beauty of a Number)

[LeetCode 原题链接](https://leetcode.cn/problems/find-the-k-beauty-of-a-number/) | 难度: **简单** | 标签: `数学`、`字符串`、`滑动窗口`

## 题目描述

一个整数 `num` 的 k 美丽值定义为 `num` 中符合以下条件的 子字符串 数目:

- 子字符串长度为 `k`.
- 子字符串能整除 `num`.

给你整数 `num` 和 `k`, 请你返回 `num` 的 k 美丽值.

注意:

- 允许有 前缀0.
- `0` 不能整除任何值.

一个 子字符串 是一个字符串里的连续一段字符序列.

示例:

```plaintext
输入: num = 240, k = 2
输出: 2
解释: 以下是 num 里长度为 k 的子字符串:
    - "_**24**_ 0" 中的 "24": 24 能整除 240.
    - "2 _**40**_ " 中的 "40": 40 能整除 240.
    所以, k 美丽值为 2.
```

## 解法思路

### 遍历 枚举

- 时间复杂度: O(nk) n为num长度 k为字串长度
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int divisorSubstrings(int num, int k) {
            string s = to_string(num);
            int n = s.size();
            int res = 0;
            for (int i = 0; i < n - k + 1; i++) {
                int tmp = stoi(s.substr(i, k));
                if (tmp != 0 && num % tmp == 0) {
                    res++;
                }
            }
            return res;
        }
};
```

## Tags

[数学](/tags/math.md) | [字符串](/tags/string.md) | [滑动窗口](/tags/sliding-window.md)
