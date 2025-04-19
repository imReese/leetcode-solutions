# 2563. 统计公平数对的数目 (Count the Number of Fair Pairs)

[LeetCode 原题链接](https://leetcode.cn/problems/count-the-number-of-fair-pairs/) | 难度: **中等** | 标签: `数组`、`双指针`、`二分查找`、`排序`

## 题目描述

给你一个下标从 **0** 开始、长度为 `n` 的整数数组 `nums`, 和两个整数 `lower` 和 `upper`, 返回 **公平数对的数目**.

如果 `(i, j)` 数对满足以下情况, 则认为它是一个 **公平数对**:

- `0 <= i < j < n`, 且
- `lower <= nums[i] + nums[j] <= upper`

示例:

```plaintext
输入: nums = [0,1,7,4,4,5], lower = 3, upper = 6
输出: 6
解释: 共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) .
```

## 解法思路

### 排序+二分查找

- 核心思想: `lower <= nums[i] + nums[j] < = upper` 可以转化为 `lower - nums[j] <= nums[i] <= upper - nums[j]` 则可以遍历j 找出nums中符合大于`lower - nums[j]`且小于`upper - nums[j]`的i的个数
- 时间复杂度: O(nlogn)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            long long res = 0;
            sort(nums.begin(), nums.end());
            for (int j = 0; j < nums.size(); j++) {
                auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
                auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
                res += r - l;
            }
            return res;
        }
};
```

## 相似题目

- [327. 区间和的个数](https://leetcode.cn/problems/count-of-range-sum/)

## Tags

[数组](/tags/array.md) | [双指针](/tags/two-pointers.md) | [二分查找](/tags/binary-search.md) | [排序](/tags/sorting.md)
