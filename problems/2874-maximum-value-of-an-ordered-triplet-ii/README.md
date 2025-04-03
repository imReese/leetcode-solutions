# 2874. 有序三元组中的最大值 II (Maximum Value of an Ordered Triplet II)

[LeetCode 原题链接](https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii) | 难度: **中等** | 标签: `数组`

## 题目描述

给你一个下标从 0 开始的整数数组 `nums` .

请你从所有满足 `i < j < k` 的下标三元组 `(i, j, k)` 中, 找出并返回下标三元组的最大值. 如果所有满足条件的三元组的值都是负数, 则返回 `0` .

下标三元组 `(i, j, k)` 的值等于 `(nums[i] - nums[j]) * nums[k]` .

示例:

```plaintext
输入: nums = [12,6,1,2,7]
输出: 77
解释: 下标三元组 (0, 2, 4) 的值是 (nums[0] - nums[2]) * nums[4] = 77 . 
    可以证明不存在值大于 77 的有序下标三元组. 
```

## 解法思路

### 贪心 + 前后缀数组

- 核心思想: 使用 leftMax[i] 和 rightMax[j] 维护前缀 `[0, i)` 最大值和后缀 `[j+1, n)` 最大值
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            vector<int> leftMax(n, 0);
            vector<int> rightMax(n, 0);
            leftMax[0] = nums[0];
            rightMax[n - 1] = nums[n - 1];
            for (int i = 1; i < n; i++) {
                leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
                rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
            }
            for (int i = 1; i < n - 1; i++) {
                res = max(res, (long long)(leftMax[i] - nums[i]) * rightMax[i]);
            }
            return res;
        }
};
```

## 相似题目

- [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/)

## Tags

[数组](/tags/array.md)
