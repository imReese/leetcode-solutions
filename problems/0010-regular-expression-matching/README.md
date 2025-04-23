# 10. 正则表达式匹配 (Regular Expression Matching)

[LeetCode 原题链接](https://leetcode.cn/problems/regular-expression-matching/) | 难度: **困难** | 标签: `递归`、`字符串`、`动态规划`

## 题目描述

给你一个字符串 `s` 和一个字符规律 `p`, 请你来实现一个支持 `'.'` 和 `'*'` 的正则表达式匹配.

- `'.'` 匹配任意单个字符
- `'*'` 匹配零个或多个前面的那一个元素

所谓匹配, 是要涵盖 **整个** 字符串 `s` 的, 而不是部分字符串.

示例:

```plaintext
输入: s = "aa", p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串.
```

## 解法思路

### 动态规划

- 核心思想: `dp[i][j]` 表示 `s[0..i-1]` 和 `p[0..j-1]` 是否匹配
  - 状态转移:
    - `s[i] == p[j]` 或 `p[j] == '.'` 时, `dp[i][j] = dp[i-1][j-1]`
    - 当 `s[i] != p[j]` 且 `p[j] != '.'` 时, `dp[i][j] = false`
    - 当 `s[i] != p[j]` 但 `p[j] == '*'` 时, 有两种情况:
      - `p[j-1]` 和 `s[i]` 不匹配 `*` 视为前元素 `p[j-1]` 为0个, 则 `dp[i][j] = dp[i][j-2]`
      - `p[j-1]` 和 `s[i]` 匹配   `*` 可以把前元素 `p[j-1]` 视为0个或多个的匹配, 则 `dp[i][j] = dp[i-1][j]`

- 时间复杂度: O(mn) mn 为字符串 s 和 p 的长度
- 空间复杂度: O(mn)

```cpp
class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.size();
            int n = p.size();
            auto matches = [&](int i, int j) {
                if (i == 0) {
                    return false;
                }
                if (p[j - 1] == '.') {
                    return true;
                }
                return s[i - 1] == p[j - 1];
            };
            vector<vector<int>> f(m + 1,vector<int>(n + 1));
            f[0][0] = true;
            for (int i = 0; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (p[j - 1] == '*') {
                        f[i][j] |= f[i][j - 2];
                        if (matches(i, j - 1)) {
                            f[i][j] |= f[i - 1][j];
                        }
                    } else {
                        if (matches(i, j)) {
                            f[i][j] |= f[i - 1][j - 1];
                        }
                    }
                }
            }
            return f[m][n];
        }
};
```

## 相似题目

- [44. 通配符匹配](https://leetcode.cn/problems/wildcard-matching/)

## Tags

[递归](/tags/recursion.md) | [字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md) |
