# 2843. 统计对称整数的数目 (  Count Symmetric Integers)

[LeetCode 原题链接](https://leetcode.cn/problems/count-symmetric-integers/) | 难度: **简单** | 标签: `数学`、`枚举`

## 题目描述

给你两个正整数 `low` 和 `high`.

对于一个由 `2 * n` 位数字组成的整数 `x`, 如果其前 `n` 位数字之和与后 `n` 位数字之和相等, 则认为这个数字是一个对称整数.

返回在 `[low, high]` 范围内的 对称整数的数目.

示例:

```plaintext
输入: low = 1, high = 100
输出: 9
解释: 在 1 到 100 范围内共有 9 个对称整数: 11、22、33、44、55、66、77、88 和 99.
```

## 解法思路

### 枚举

- 时间复杂度: O(high - low)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res = 0;
            for (int a = low; a <= high; a++) {
                if (a < 100 && a % 11 == 0) {
                    res++;
                } else if (a >= 1000 && a < 10000) {
                    int left = a / 1000 + (a % 1000) / 100;
                    int right = (a % 100) / 10 + a % 10;
                    if (left == right) {
                        res++;
                    }
                }
            }
            return res;
        }
};
```

## 相似题目

- [9. 回文数](https://leetcode.cn/problems/palindrome-number/)

## Tags

[数学](/tags/math.md) | [枚举](/tags/enumeration.md)
