# 2338. 统计理想数组的数目 (Count the Number of Ideal Arrays)

[LeetCode 原题链接](https://leetcode.cn/problems/count-the-number-of-ideal-arrays/) | 难度: **困难** | 标签: `数学`、`动态规划`、`组合数学`、`数论`

## 题目描述

给你两个整数 `n` 和 `maxValue`, 用于描述一个 **理想数组**.

对于下标从 **0** 开始、长度为 `n` 的整数数组 `arr`, 如果满足以下条件, 则认为该数组是一个 **理想数组**:

- 每个 `arr[i]` 都是从 `1` 到 `maxValue` 范围内的一个值, 其中 `0 <= i < n`.
- 每个 `arr[i]` 都可以被 `arr[i - 1]` 整除, 其中 `0 < i < n`.

返回长度为 `n` 的 **不同** 理想数组的数目. 由于答案可能很大, 返回对 `109 + 7` 取余的结果.

示例:

```plaintext
输入: n = 2, maxValue = 5
输出: 10
解释: 存在以下理想数组:
    - 以 1 开头的数组(5 个): [1,1]、[1,2]、[1,3]、[1,4]、[1,5]
    - 以 2 开头的数组(2 个): [2,2]、[2,4]
    - 以 3 开头的数组(1 个): [3,3]
    - 以 4 开头的数组(1 个): [4,4]
    - 以 5 开头的数组(1 个):[5,5]
    共计 5 + 2 + 1 + 1 + 1 = 10 个不同理想数组.
```

## 解法思路

### 组合数学

- 核心思想: 首先对maxValue进行质因数分解, 然后对于每个质因数p, 计算出它的指数e, 以及它在理想数组中的贡献.
- 时间复杂度: O(maxValue * log(maxValue) + n)
- 空间复杂度: O(n+maxValue)

```cpp
const int MOD = 1e9 + 7;
class Solution {
    private:
        vector<int> sieve(int n) {
            vector<int> min_prime(n + 1, 0);
            for (int i = 2; i <= n; i++) {
                if (min_prime[i] == 0) {
                    min_prime[i] = i;
                    for (int j = 2 * i; j <= n; j += i) {
                        if (min_prime[j] == 0) {
                            min_prime[j] = i;
                        }
                    }
                }
            }
            return min_prime;
        }
        int pow_mod(int a, int b, int mod) {
            int res = 1;
            while (b > 0) {
                if (b & 1) {
                    res = (long long)res * a % mod;
                }
                a = (long long)a * a % mod;
                b >>= 1;
            }
            return res;
        }
    public:
        int idealArrays(int n, int maxValue) {
            if (maxValue < 1) {
                return 0;
            }
            vector<int> min_prime = sieve(maxValue);
            int max_k = maxValue + n;
            vector<int> fact(max_k + 1, 1);
            vector<int> inv_fact(max_k + 1, 1);
            for (int i = 1; i <= max_k; i++) {
                fact[i] = (long long)fact[i - 1] * i % MOD;
            }
            inv_fact[max_k] = pow_mod(fact[max_k], MOD - 2, MOD);
            for (int i = max_k - 1; i >= 0; i--) {
                inv_fact[i] = (long long)inv_fact[i + 1] * (i + 1) % MOD;
            }
            long long ans = 0;
            for (int v = 1; v <= maxValue; v++) {
                if (v == 1) {
                    ans = (ans + 1) % MOD;
                    continue;
                }
                unordered_map<int, int> factors;
                int x = v;
                while (x > 1) {
                    int p = min_prime[x];
                    int cnt = 0;
                    while (x % p == 0) {
                        cnt++;
                        x /= p;
                    }
                    factors[p] = cnt;
                }
                long long contribution = 1;
                for (auto& [p, e] : factors) {
                    int k = e + n - 1;
                    if (k > max_k) {
                        return - 1;
                    }
                    long long c = (long long)fact[k] * inv_fact[n - 1] % MOD;
                    c = c * inv_fact[k - (n - 1)] % MOD;
                    contribution = contribution * c % MOD;
                }
                ans = (ans + contribution) % MOD;
            }
            return ans % MOD;
        }
};
```

## 相似题目

- [1735. 生成乘积数组的方案数](https://leetcode.cn/problems/count-ways-to-make-array-with-product/)

## Tags

[数学](/tags/math.md) | [动态规划](/tags/dynamic-programming.md) | [组合数学](/tags/combinatorics.md) | [数论](/tags/number-theory.md)
