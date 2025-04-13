# 3405. 统计恰好有 K 个相等相邻元素的数组数目 (Count the Number of Arrays with K Matching Adjacent Elements)

[LeetCode 原题链接](https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/) | 难度: **困难** | 标签: `数学`、`组合数学`

## 题目描述

给你三个整数 `n`, `m`, `k`. 长度为 `n` 的 **好数组** `arr` 定义如下:

- `arr` 中每个元素都在 **闭 区间** `[1, m]` 中.
- **恰好** 有 `k` 个下标 `i`(其中 `1 <= i < n`)满足 `arr[i - 1] == arr[i]`.

请你返回可以构造出的 **好数组**  数目.

由于答案可能会很大, 请你将它对 `109 + 7` **取余** 后返回.

示例:

```plaintext
输入: n = 3, m = 2, k = 1

输出: 4

解释:
  * 总共有 4 个好数组, 分别是 `[1, 1, 2]`, `[1, 2, 2]`, `[2, 1, 1]` 和 `[2, 2, 1]`.
  * 所以答案为 4.
```

## 解法思路

### 组合数学

- 核心思想: 总的方案数为```C(k, n-1) * (m-1)^(n-1-k) * m % mod```
- 时间复杂度: O(k + logn)
- 空间复杂度: O(1)

```cpp
class Solution {
    private:
        static constexpr int mod = 1000000007;
    public:
        int countGoodArrays(int n, int m, int k) {
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
            auto comb = [&](long long n, long long k) -> long long {
                if (k > n) {
                    return 0;
                }
                if (k == 0 || k == n) {
                    return 1;
                }
                k = min(k, n - k);
                int ret = 1;
                for (int i = 1; i <= k; i++) {
                    ret = (long long)ret * (n - i + 1) % mod;
                    ret = (long long)ret * quickmul(i, mod - 2) % mod;
                }
                return ret % mod;
            };
            int res = (long long)comb(n - 1, k) % mod;
            res = (long long)res * quickmul(m - 1, n - 1 - k) % mod;
            res = (long long)res * m % mod;
            return res;
        }
};
```

## 相似题目

- [1922. 统计好数字的数目](https://leetcode.cn/problems/count-good-numbers/)

## Tags

[数学](/tags/math.md) | [组合数学](/tags/combinatorics.md)
