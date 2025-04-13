# 1922. 统计好数字的数目 (Count Good Numbers)

[LeetCode 原题链接](https://leetcode.cn/problems/count-good-numbers/) | 难度: **中等** | 标签: `递归`、`数学`

## 题目描述

我们称一个数字字符串是 **好数字** 当它满足（下标从 **0** 开始）**偶数** 下标处的数字为 **偶数** 且 **奇数** 下标处的数字为 **质数** (`2`, `3`, `5` 或 `7`).

- 比方说, `"2582"` 是好数字, 因为偶数下标处的数字（`2` 和 `8`）是偶数且奇数下标处的数字（`5` 和 `2`）为质数. 但 `"3245"` **不是** 好数字, 因为 `3` 在偶数下标处但不是偶数.

给你一个整数 `n`, 请你返回长度为 `n` 且为好数字的数字字符串 **总数**. 由于答案可能会很大, 请你将它对 `109 + 7` **取余后返回**.

一个 **数字字符串** 是每一位都由 `0` 到 `9` 组成的字符串, 且可能包含前导 0.

示例:

```plaintext
输入: n = 1
输出: 5
解释: 长度为 1 的好数字包括 "0", "2", "4", "6", "8".    
```

## 解法思路

### 快速幂

- 核心思想: 偶数下标可以为0,2,4,6,8 有5种 奇数下标可以为2,3,5,7 有四种 故答案为5^偶数下标个数 * 4^奇数下标个数 使用快速幂计算
- 时间复杂度: O(logn)
- 空间复杂度: O(1)

```cpp
class Solution {
    private:
        static constexpr int mod = 1000000007;
    public:
        int countGoodNumbers(long long n) {
            auto quickmul = [](int x, long long y) -> int {
                int ret = 1, mul = x;
                while (y > 0) {
                    if (y % 2 == 1) {
                        ret = (long long)ret * mul % mod;
                    }
                    mul = (long long)mul * mul % mod;
                    y /= 2;
                }
                return ret;
            };
            int res = (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
            return res;
        }
};
```

## 相似题目

- [3405. 统计恰好有 K 个相等相邻元素的数组数目](https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/)

## Tags

[递归](/tags/recursion.md) | [数学](/tags/math.md)
