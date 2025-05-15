# 2900. 最长相邻不相等子序列 I (Longest Unequal Adjacent Groups Subsequence I)

[LeetCode 原题链接](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/) | 难度: **简单** | 标签: `贪心`、`数组`、`字符串`、`动态规划`

## 题目描述

给你一个下标从 **0** 开始的字符串数组 `words`, 和一个下标从 **0** 开始的 **二进制** 数组 `groups`, 两个数组长度都是 `n`.

你需要从 `words` 中选出 **最长子序列**. 如果对于序列中的任何两个连续串, 二进制数组 `groups` 中它们的对应元素不同, 则 `words` 的子序列是不同的.

正式来说, 你需要从下标 `[0, 1, ..., n - 1]` 中选出一个 **最长子序列**, 将这个子序列记作长度为 `k` 的 `[i0, i1, ..., ik - 1]`, 对于所有满足 `0 <= j < k - 1` 的 `j` 都有 `groups[ij] != groups[ij + 1]`.

请你返回一个字符串数组, 它是下标子序列 **依次** 对应 `words` 数组中的字符串连接形成的字符串数组. 如果有多个答案, 返回 **任意** 一个.

**注意:** `words` 中的元素是不同的.

示例:

```plaintext
输入: words = ["e","a","b"], groups = [0,0,1]
输出: ["e","b"]
解释:
    一个可行的子序列是 [0,2], 因为 groups[0] != groups[2].
    所以一个可行的答案是 [words[0], words[2]] = ["e","b"].
    另一个可行的子序列是 [1,2], 因为 groups[1] != groups[2].
    得到答案为 [words[1],words[2]] = ["a","b"].
    这也是一个可行的答案.
    符合题意的最长子序列的长度为 2.
[/code]
```

## 解法思路

### 方法一: 动态规划

- 核心思想: 使用动态规划来维护两个路径, 一个路径以 `0` 开始, 另一个路径以 `1` 开始. 每次遍历时，判断当前元素的组别, 并更新对应的路径长度和路径.
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        if (n == 0) {
            return {};
        }
        vector<int> path0, path1;
        int len0 = 0, len1 = 0;
        if (groups[0] == 0) {
            path0.push_back(0);
            len0 = 1;
        } else {
            path1.push_back(0);
            len1 = 1;
        }
        for (int i = 1; i < n; ++i) {
            int g = groups[i];
            if (g == 0) {
                vector<int> new_path = path0;
                int new_len = len0;
                if (len1 + 1 > len0) {
                    new_len = len1 + 1;
                    new_path = path1;
                    new_path.push_back(i);
                }
                if (new_len > len0) {
                    len0 = new_len;
                    path0 = new_path;
                }
            } else {
                vector<int> new_path = path1;
                int new_len = len1;
                if (len0 + 1 > len1) {
                    new_len = len0 + 1;
                    new_path = path0;
                    new_path.push_back(i);
                }
                if (new_len > len1) {
                    len1 = new_len;
                    path1 = new_path;
                }
            }
        }
        vector<string> res;
        if (len0 >= len1) {
            for (int idx : path0) res.push_back(words[idx]);
        } else {
            for (int idx : path1) res.push_back(words[idx]);
        }
        return res;
    }
};
```

### 方法二: 贪心

- 核心思想: 使用贪心算法, 每次选择当前元素的组别与前一个元素不同的元素, 直到遍历完所有元素.
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```go
func getLongestSubsequence(words []string, groups []int) []string {
    var res []string
    n := len(words)
    for i := 0; i < n; i++ {
        if i == 0 || groups[i] != groups[i-1] {
            res = append(res, words[i])
        }
    }
    return res
}
```

## Tags

[贪心](/tags/greedy.md) | [数组](/tags/array.md) | [字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md)
