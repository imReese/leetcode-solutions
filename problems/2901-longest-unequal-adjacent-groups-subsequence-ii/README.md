# 2901. 最长相邻不相等子序列 II (Longest Unequal Adjacent Groups Subsequence II)

[LeetCode 原题链接](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/) | 难度: **中等** | 标签: `数组`、`字符串`、`动态规划`

## 题目描述

给定一个字符串数组 `words`, 和一个数组 `groups`, 两个数组长度都是 `n`.

两个长度相等字符串的 **汉明距离** 定义为对应位置字符 **不同** 的数目.

你需要从下标 `[0, 1, ..., n - 1]` 中选出一个 **最长子序列**, 将这个子序列记作长度为 `k` 的 `[i0, i1, ..., ik - 1]`, 它需要满足以下条件:

- **相邻** 下标对应的 `groups` 值 **不同**. 即, 对于所有满足 `0 < j + 1 < k` 的 `j` 都有 `groups[ij] != groups[ij + 1]`.
- 对于所有 `0 < j + 1 < k` 的下标 `j`, 都满足 `words[ij]` 和 `words[ij + 1]` 的长度 **相等**, 且两个字符串之间的 **汉明距离** 为 `1`.

请你返回一个字符串数组, 它是下标子序列 **依次** 对应 `words` 数组中的字符串连接形成的字符串数组. 如果有多个答案, 返回任意一个.

**子序列** 指的是从原数组中删掉一些(也可能一个也不删掉)元素, 剩余元素不改变相对位置得到的新的数组.

**注意：**`words` 中的字符串长度可能 **不相等**.

示例:

```plaintext
输入: words = ["bab","dab","cab"], groups = [1,2,2]
输出: ["bab","cab"]
解释:
一个可行的子序列是 [0,2].
    - groups[0] != groups[2]
    - words[0].length == words[2].length 且它们之间的汉明距离为 1.
所以一个可行的答案是 [words[0],words[2]] = ["bab","cab"].
另一个可行的子序列是 [0,1].
    - groups[0] != groups[1]
    - words[0].length = words[1].length 且它们之间的汉明距离为 1.
所以另一个可行的答案是 [words[0],words[1]] = ["bab","dab"].
    符合题意的最长子序列的长度为 2.
```

## 解法思路

### 动态规划

- 核心思想: dp[i] 表示以 i 结尾的最长子序列长度, prev[i] 表示 i 的前一个元素的下标.
- 时间复杂度: O(n²)
- 空间复杂度: O(n)

```cpp
class Solution {
private:
    bool isAdjacent(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int max_len = 1;
        int max_idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && isAdjacent(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_idx = i;
            } else if (dp[i] == max_len) {
                max_idx = i;
            }
        }
        vector<int> path;
        int curr = max_idx;
        while (curr != -1) {
            path.push_back(curr);
            curr = prev[curr];
        }
        reverse(path.begin(), path.end());
        vector<string> res;
        for (int i : path) {
            res.push_back(words[i]);
        }
        return res;
    }
};
```

## Tags

[数组](/tags/array.md) | [字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md)
