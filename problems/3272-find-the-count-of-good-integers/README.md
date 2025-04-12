# 3272. 统计好整数的数目 (Find the Count of Good Integers)

[LeetCode 原题链接](https://leetcode.cn/problems/find-the-count-of-good-integers/) | 难度: **困难** | 标签: `哈希表`、`数学`、`组合数学`、`枚举`

## 题目描述

给你两个 正 整数 `n` 和 `k`.

如果一个整数 `x` 满足以下条件, 那么它被称为 k 回文 整数.

- `x` 是一个 回文整数.
- `x` 能被 `k` 整除.

如果一个整数的数位重新排列后能得到一个 k 回文整数, 那么我们称这个整数为 好 整数. 比方说, `k = 2`, 那么 2020 可以重新排列得到 2002, 2002 是一个 k 回文串, 所以 2020 是一个好整数. 而 1010 无法重新排列数位得到一个 k 回文整数.

请你返回 `n` 个数位的整数中, 有多少个 好 整数.

注意, 任何整数在重新排列数位之前或者之后 都不能 有前导 0. 比方说 1010 不能重排列得到 101.

示例:

```plaintext
输入: n = 3, k = 5

输出: 27

解释:

部分好整数如下:

  * 551, 因为它可以重排列得到 515.
  * 525, 因为它已经是一个 k 回文整数.
```

## 解法思路

### 枚举+排列组合

- 核心思想: 枚举所有n位回文数判断是否可以被k整除得到k回文整数, 之后统计k回文整数各数位的个数, 之后进行排列组合得到结果.
- 时间复杂度: O(nlogn*10^m) (m为n的一半)
- 空间复杂度: O(n*10^m) )

```cpp
class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            long long res = 0;
            unordered_set<string> dict;
            int base = pow(10, (n - 1) / 2);
            int skip = n & 1;
            for (int i = base; i < base * 10; i++) {
                string s = to_string(i);
                s += string(s.rbegin() + skip, s.rend());
                long long palindromicInterger = stoll(s);
                if (palindromicInterger % k == 0) {
                    sort(s.begin(), s.end());
                    dict.emplace(s);
                }
            }
            vector<long long> factorial(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                factorial[i] = factorial[i - 1] * i;
            }
            for (const string &s : dict) {
                vector<int> cnt(10);
                for (char c : s) {
                    cnt[c - '0']++;
                }
                long long tot = (n - cnt[0]) * factorial[n - 1];
                for (int x : cnt) {
                    tot /= factorial[x];
                }
                res += tot;
            }
            return res;
        }
};
```

## 相似题目

- [9. 回文数](https://leetcode.cn/problems/palindrome-number/)

- Tags

[哈希表](/tags/hash-table.md) | [数学](/tags/math.md) | [组合数学](/tags/combinatorics.md) | [枚举](/tags/enumeration.md)
