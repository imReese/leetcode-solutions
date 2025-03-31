# 633. 平方数之和 (Sum of Square Numbers)

[LeetCode 原题链接](https://leetcode.cn/problems/sum-of-square-numbers/) | 难度: **中等** | 标签: `数学`、`双指针`、`二分查找`

## 题目描述

给定一个非负整数 `c`, 你要判断是否存在两个整数 `a` 和 `b`, 使得 `a2 + b2 = c`.

示例:

```plaintext
输入: c = 5
输出: true
解释: 1 * 1 + 2 * 2 = 5
```

## 解法思路

### 双指针

- 时间复杂度: O(sqrt(n))
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        bool judgeSquareSum(int c) {
            long left = 0;
            long right = (int)sqrt(c);
            while (left <= right) {
                long sum = left * left + right * right;
                if (sum == c) {
                    return true;
                } else if (sum < c) {
                    left++;
                } else if (sum > c) {
                    right--;
                }
            }
            return false;
        }
};
```

### 数学

- 核心思想: 费马平方和定理: 一个非负整数 c 如果能够表示为两个整数的平方和, 当且仅当 c 的所有形如 4k+3 的质因子的幂均为偶数.
- 时间复杂度: O(sqrt(n))
- 空间复杂度: O(1)

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int base = 2; base * base <= c; base++) {
            if (c % base != 0) {
                continue;
            }
            int exp = 0;
            while (c % base == 0) {
                c /= base;
                exp++;
            }
            if (base % 4 == 3 && exp % 2 != 0) {
                return false;
            }
        }
        return c % 4 != 3;
    }
};
```

## 相似题目

- [367. 有效的完全平方数](https://leetcode.cn/problems/valid-perfect-square/)

## Tags

[数学](/tags/math.md) | [双指针](/tags/two-pointers.md) | [二分查找](/tags/binary-search.md)
