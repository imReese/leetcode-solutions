# 1278. 分割回文串 III (Palindrome Partitioning III)

[LeetCode 原题链接](https://leetcode.cn/problems/palindrome-partitioning-iii/) | 难度: **困难** | 标签: `字符串`、`动态规划`

## 题目描述

给你一个由小写字母组成的字符串 `s`, 和一个整数 `k`.

请你按下面的要求分割字符串:

- 首先, 你可以将 `s` 中的部分字符修改为其他的小写英文字母.
- 接着, 你需要把 `s` 分割成 `k` 个非空且不相交的子串, 并且每个子串都是回文串.

请返回以这种方式分割字符串所需修改的最少字符数.

示例:

```plaintext
输入: s = "abc", k = 2
输出: 1
解释: 你可以把字符串分割成 "ab" 和 "c", 并修改 "ab" 中的 1 个字符, 将它变成回文串.
```

## 解法思路

### 动态规划

- 核心思想: dp[i][j] 表示前 i 个字符分割成 j 个回文串的最小修改次数
  - 状态转移方程: dp[i][j] = min(dp[i0][j-1] + cost(s, i0, i-1)), 其中 i0 从 j-1 到 i-1
- 时间复杂度: O(n³k)
- 空间复杂度: O(nk)

```cpp
class Solution {
    public:
        int cost(string& s, int l, int r) {
            int ret = 0;
            for (int i = l, j = r; i < j; i++, j--) {
                if (s[i] != s[j]) {
                    ret++;
                }
            }
            return ret;
        }

        int palindromePartition(string s, int k) {
            int n = s.size();
            vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
            f[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= min(k, i); j++) {
                    if (j == 1) {
                        f[i][j] = cost(s, 0, i - 1);
                    } else {
                        for (int i0 = j - 1; i0 < i; i0++) {
                            f[i][j] = min(f[i][j], f[i0][j - 1] + cost(s, i0, i - 1));
                        }
                    }
                }
            }
            return f[n][k];
        }
};
```

## 相似题目

- [2472. 不重叠回文子字符串的最大数目](https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

## Tags

[字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md)
