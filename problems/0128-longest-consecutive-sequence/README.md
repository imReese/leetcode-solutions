# 128. 最长连续序列 (Longest Consecutive Sequence)

[LeetCode 原题链接](https://leetcode.cn/problems/longest-consecutive-sequence/) | 难度: **中等** | 标签: `并查集`、`数组`、`哈希表`

## 题目描述

给定一个未排序的整数数组 `nums`, 找出数字连续的最长序列(不要求序列元素在原数组中连续)的长度.

请你设计并实现时间复杂度为 _`O(n)`_ 的算法解决此问题.

示例:

```plaintext
输入: nums = [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长数字连续序列是 [1, 2, 3, 4]. 它的长度为 4.
```

## 解法思路

### 哈希表

- 核心思想: 将数组中数字存入哈希表中 当哈希表中不存在num-1元素时说明num为序列起点 然后不断+1判断哈希表中是否存在num+1元素 直到不存在为止
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_len = 0;
        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int current = num, current_len = 1;
                while (num_set.count(current + 1)) {
                    current++;
                    current_len++;
                }
                max_len = max(max_len, current_len);
            }
        }
        return max_len;
    }
};
```

## 相似题目

- [2177. 找到和为给定整数的三个连续整数](https://leetcode.cn/problems/find-three-consecutive-integers-that-sum-to-a-given-number/)

## Tags

[并查集](/tags/union-find.md) | [数组](/tags/array.md) | [哈希表](/tags/hash-table.md)
