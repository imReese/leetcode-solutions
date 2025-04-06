# 3138. 同位字符串连接的最小长度 (Minimum Length of Anagram Concatenation)

[LeetCode 原题链接](https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/) | 难度: **中等** | 标签: `哈希表`、`字符串`、`计数`

## 题目描述

给你一个字符串 `s`, 它由某个字符串 `t` 和若干 `t`  的 同位字符串  连接而成.

请你返回字符串 `t` 的 最小 可能长度.

同位字符串 指的是重新排列一个字符串的字母得到的另外一个字符串. 例如, "aab"，"aba" 和 "baa" 是 "aab" 的同位字符串.

示例:

```plaintext
输入: s = "abba"
输出: 2
解释:
一个可能的字符串 `t` 为 `"ba"`.
```

## 解法思路

### 枚举

- 核心思想: 枚举所有可能的t的长度k, 然后判断s是否可以由k个t组成.
- 时间复杂度: O(nT) n是字符串s的长度 T是n的因数数目
- 空间复杂度: O(∑) ∑是字符集的大小26  

```cpp
class Solution {
    public:
        int minAnagramLength(string s) {
            int n = s.size();
            unordered_map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }
            vector<int> factors;
            for (int i = 1; i <= n; ++i) {
                if (n % i == 0) {
                    factors.push_back(i);
                }
            }
            for (int k : factors) {
                int m = n / k;
                bool valid = true;
                for (const auto& pair : freq) {
                    if (pair.second % m != 0) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                string first = s.substr(0, k);
                sort(first.begin(), first.end());
                bool ok = true;
                for (int i = 1; i < m; ++i) {
                    string current = s.substr(i * k, k);
                    sort(current.begin(), current.end());
                    if (current != first) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return k;
                }
            }
            return n;
        }
};
```

## Tags

[哈希表](/tags/hash-table.md) | [字符串](/tags/string.md)
