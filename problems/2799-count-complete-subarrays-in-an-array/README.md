# 2799. 统计完全子数组的数目 (Count Complete Subarrays in an Array)

[LeetCode 原题链接](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/) | 难度: **中等** | 标签: `数组`、`哈希表`、`滑动窗口`

## 题目描述

给你一个由 **正** 整数组成的数组 `nums`.

如果数组中的某个子数组满足下述条件, 则称之为 **完全子数组**:

- 子数组中 **不同** 元素的数目等于整个数组不同元素的数目.

返回数组中 **完全子数组** 的数目.

**子数组** 是数组中的一个连续非空序列.

示例:

```plaintext
输入: nums = [1,3,1,2,2]
输出: 4
解释: 完全子数组有: [1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2].
```

## 解法思路

### 滑动窗口+哈希表

- 核心思想: 首先记录nums中所有不同数的个数 然后使用滑动窗口调整左右边界, 右指针右移过程中判断是否包含所有不同数 左指针右移过程中删除左边界元素
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int res = 0;
            int n = nums.size();
            unordered_set<int> distinct(nums.begin(), nums.end());
            int distinct_count = distinct.size();
            int right = 0;
            unordered_map<int, int> cnt;
            for (int left = 0; left < n; left++) {
                if (left > 0) {
                    int remove = nums[left - 1];
                    cnt[remove]--;
                    if (cnt[remove] == 0) {
                        cnt.erase(remove);
                    }
                }
                while (right < n && cnt.size() < distinct_count) {
                    int add = nums[right];
                    cnt[add]++;
                    right++;
                }
                if (cnt.size() == distinct_count) {
                    res += (n - right + 1);
                }
            }
            return res;
        }
};
```

## 相似题目

- [2799. 统计完全子数组的数目](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [滑动窗口](/tags/sliding-window.md)
