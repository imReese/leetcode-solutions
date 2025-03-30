# 2109. 向字符串添加空格 (Adding Spaces to a String)

[LeetCode 原题链接](https://leetcode.cn/problems/adding-spaces-to-a-string/) | 难度: **中等** | 标签: `数组`、`双指针`、`字符串`、`模拟`

## 题目描述

给你一个下标从 0 开始的字符串 s , 以及一个下标从 0 开始的整数数组 spaces .

数组 spaces 描述原字符串中需要添加空格的下标. 每个空格都应该插入到给定索引处的字符值 之前 .

例如, s = "EnjoyYourCoffee" 且 spaces = [5, 9] , 那么我们需要在 'Y' 和 'C' 之前添加空格, 这两个字符分别位于下标 5 和下标 9 . 因此, 最终得到 "Enjoy Your Coffee" .

请你添加空格, 并返回修改后的字符串.

示例:

```plaintext
输入: s = "LeetcodeHelpsMeLearn", spaces = [8, 13, 15]
输出: "Leetcode Helps Me Learn"
解释: 
下标 8、13 和 15 对应 "LeetcodeHelpsMeLearn" 中加粗斜体字符. 
接着在这些字符前添加空格. 
```

## 解法思路

### 双指针

- 时间复杂度: O(m + n), 其中 m 为字符串长度, n为空格数组长度.
- 空间复杂度: O(m + n), 其中 m 为字符串长度, n为空格数组长度.

```cpp
class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
            int m = s.size();
            int n = spaces.size();
            string res = "";
            int i = 0;
            int j = 0;
            while(i < m && j < n) {
                if(i == spaces[j]) {
                    res += " ";
                    j++;
                } else {
                    res += s[i];
                    i++;
                }
            }
            while(i < m) {
                res += s[i];
                i++;
            }
            return res;
        }
};
```

## Tags

[数组](/tags/array.md)、[双指针](/tags/two-pointers.md)、[字符串](/tags/string.md)、[模拟](/tags/simulation.md)
