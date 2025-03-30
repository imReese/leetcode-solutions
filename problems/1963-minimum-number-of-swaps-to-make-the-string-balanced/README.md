# 1963. 使字符串平衡的最小交换次数 (Minimum Number of Swaps to Make the String Balanced)

[LeetCode 原题链接](https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/) | 难度: **中等** | 标签: `栈`、`贪心`、`双指针`、`字符串`

## 题目描述

给你一个字符串 s , 下标从 0 开始 , 且长度为偶数 n . 字符串 恰好 由 n / 2 个开括号 '['和 n / 2 个闭括号 ']'组成.

只有能满足下述所有条件的字符串才能称为 平衡字符串:

- 字符串是一个空字符串, 或者
- 字符串可以记作 AB , 其中 A 和 B 都是 平衡字符串 , 或者
- 字符串可以写成 [C] , 其中 C 是一个 平衡字符串 .
你可以交换 任意 两个下标所对应的括号 任意 次数.

返回使 s 变成 平衡字符串 所需要的 最小 交换次数.

示例:

```plaintext
输入: s = "][]["
输出: 1
解释: 交换下标 0 和下标 3 对应的括号, 可以使字符串变成平衡字符串.
最终字符串变成 "[[]]" .
```

## 解法思路

### 模拟 + 栈

- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int minSwaps(string s) {
            int res = 0;
            int count = 0;
            for(char c : s) {
                if(c == '[') {
                    count++;
                } else {
                    if(count > 0) {
                        count--;
                    } else {
                        res++;
                    }
                }
            }
            return (res + 1) / 2;
        }
};
```

### 关键点

- res 为不平衡括号对的数量, 交换次数为res的一半即可.

## 相似题目

- [301. 删除无效的括号](https://leetcode.cn/problems/remove-invalid-parentheses/)

## Tags

[栈](/tags/stack.md) [贪心](/tags/greedy.md) [双指针](/tags/two-pointers.md) [字符串](/tags/string.md)
