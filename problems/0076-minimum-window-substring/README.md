# 76. 最小覆盖子串 (Minimum Window Substring)

[LeetCode 原题链接](https://leetcode.cn/problems/minimum-window-substring/) | 难度: **困难** | 标签: `哈希表`、`字符串`、`滑动窗口`

## 题目描述

给你一个字符串 `s` 、一个字符串 `t`. 返回 `s` 中涵盖 `t` 所有字符的最小子串. 如果 `s` 中不存在涵盖 `t` 所有字符的子串，则返回空字符串 `""`.

**注意:**

- 对于 `t` 中重复字符, 我们寻找的子字符串中该字符数量必须不少于 `t` 中该字符数量.
- 如果 `s` 中存在这样的子串, 我们保证它是唯一的答案.

示例:

```plaintext
输入: s = "ADOBECODEBANC", t = "ABC"
输出: "BANC"
解释: 最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'.
```

## 解法思路

### 滑动窗口

- 核心思想: 使用哈希表分别记录t中字符个数已经s的字串中字符个数 移动右指针当满足子串中字符匹配t中所有字符时尝试移动左指针
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    private:
        bool check(unordered_map<char, int>& t_cnt, unordered_map<char, int>& s_cnt) {
            for (auto it = t_cnt.begin(); it != t_cnt.end(); it++) {
                if (s_cnt[it->first] < it->second) {
                    return false;
                }
            }
            return true;
        }
    public:
        string minWindow(string s, string t) {
            if (s.size() < t.size()) {
                return "";
            }
            unordered_map<char, int> t_cnt;
            for (char c : t) {
                t_cnt[c]++;
            }
            int required = t_cnt.size();
            unordered_map<char, int> s_cnt;
            int left = 0, right = 0;
            int min_len = INT_MAX;
            int ans_left = 0;
            int formed = 0;
            while (right < s.size()) {
                char c = s[right];
                s_cnt[c]++;
                if (t_cnt.count(c) && s_cnt[c] == t_cnt[c]) {
                    formed++;
                }
                while (formed == required && left <= right) {
                    if (right - left + 1 < min_len) {
                        min_len = right - left + 1;
                        ans_left = left;
                    }
                    char left_c = s[left];
                    s_cnt[left_c]--;
                    if (t_cnt.count(left_c) && s_cnt[left_c] < t_cnt[left_c]) {
                        formed--;
                    }
                    left++;
                }
                right++;
            }
            return min_len == INT_MAX ? "" : s.substr(ans_left, min_len);
        }
};
```

## 相似题目

- [30. 串联所有单词的子串](https://leetcode.cn/problems/substring-with-concatenation-of-all-words/)

## Tags

[哈希表](/tags/hash-table.md) | [字符串](/tags/string.md) | [滑动窗口](/tags/sliding-window.md)
