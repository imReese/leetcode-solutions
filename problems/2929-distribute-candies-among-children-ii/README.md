# 2929. 给小朋友们分糖果 II (Distribute Candies Among Children II)

[LeetCode 原题链接](https://leetcode.cn/problems/distribute-candies-among-children-ii/) | 难度: **中等** | 标签: `数学`、`组合数学`、`枚举`

## 题目描述

给你两个正整数 `n` 和 `limit`.

请你将 `n` 颗糖果分给 `3` 位小朋友, 确保没有任何小朋友得到超过 `limit` 颗糖果, 请你返回满足此条件下的 **总方案数**.

示例:

```plaintext
输入: n = 5, limit = 2
输出: 3
解释: 总共有 3 种方法分配 5 颗糖果, 且每位小朋友的糖果数不超过 2 : (1, 2, 2) ，(2, 1, 2) 和 (2, 2, 1).
```

## 解法思路

### 枚举

- 第一位小朋友可以分到 `0` 到 `min(limit, n)` 颗糖果. 剩下两位小朋友要分的糖果数为 `n - i`. 如果 `n - i` 大于 `2 * limit`, 则不可能满足条件, 直接跳过. 第二位小朋友可以分到 `min(n-i, limit) - max(0, n - i - limit)` 颗糖果, 在这个范围内才能满足第三位小朋友分到的糖果数也符合条件
- 时间复杂度: O(min(limit, n))
- 空间复杂度: O(1)

```cpp
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }
            ans += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return ans;
    }
};
```

## Tags

[数学](/tags/math.md) | [组合数学](/tags/combinatorial-math.md) | [枚举](/tags/enumeration.md)
