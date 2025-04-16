# 2537. 统计好子数组的数目 (Count the Number of Good Subarrays)

[LeetCode 原题链接](https://leetcode.cn/problems/count-the-number-of-good-subarrays/) | 难度: **中等** | 标签: `数组`、`哈希表`、`滑动窗口`

## 题目描述

给你一个整数数组 `nums` 和一个整数 `k`, 请你返回 `nums` 中 **好** 子数组的数目.

一个子数组 `arr` 如果有 **至少** `k` 对下标 `(i, j)` 满足 `i < j` 且 `arr[i] == arr[j]`, 那么称它是一个 **好** 子数组.

**子数组** 是原数组中一段连续 **非空** 的元素序列.

示例:

```plaintext
输入: nums = [1,1,1,1,1], k = 10
输出: 1
解释: 唯一的好子数组是这个数组本身.
```

## 解法思路

### 双指针+滑动窗口

- 核心思想: 使用双指针维护一个滑动窗口, 使用哈希表维护滑动窗口中每个元素出现的次数来判断该子数组是否为好子数组
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            int same = 0;
            unordered_map<int, int> cnt;
            long long ans = 0;
            int right = -1;
            for (int left = 0; left < n; left++) {
                while (same < k && right + 1 < n) {
                    right++;
                    same += cnt[nums[right]];
                    cnt[nums[right]]++;
                }
                if (same >= k) {
                    ans += n - right;
                }
                cnt[nums[left]]--;
                same -= cnt[nums[left]];
            }
            return ans;
        }
};
```

## 相似题目

- [1759. 统计同质子字符串的数目](https://leetcode.cn/problems/count-number-of-homogenous-substrings/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [滑动窗口](/tags/sliding-window.md)
