# 581. 最短无序连续子数组 (Shortest Unsorted Continuous Subarray)

[LeetCode 原题链接](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/) | 难度: **中等** | 标签: `栈`、`贪心`、`数组`、`双指针`、`排序`、`单调栈`

## 题目描述

给你一个整数数组 `nums`, 你需要找出一个 **连续子数组**, 如果对这个子数组进行升序排序, 那么整个数组都会变为升序排序.

请你找出符合题意的 **最短** 子数组, 并输出它的长度.

示例:

```plaintext
输入: nums = [2,6,4,8,10,9,15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序, 那么整个表都会变为升序排序.
```

## 解法思路

### 遍历

- 核心思想:
  - nums分为三个部分 左边有序部分, 中间无序部分, 右边有序部分, 一次遍历找到中间无序部分的左右边界
  - 中间部分的最小值大于左边有序部分的最大值 中间部分的最大值小于右边有序部分的最小值
  - 从左到右遍历, 用maxn记录遍历过的最大值, 当maxn大于当前值时, 说明当前值不在左边有序部分, 记录当前下标为right
  - 从右到左遍历, 用minn记录遍历过的最小值, 当minn小于当前值时, 说明当前值不在右边有序部分, 记录当前下标为left
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxn > nums[i]) {
                right = i;
            } else {
                maxn = nums[i];
            }
            if (minn < nums[n - i -1]) {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};
```

## Tags

[栈](/tags/stack.md) | [贪心](/tags/greedy.md) | [数组](/tags/array.md) | [双指针](/tags/two-pointers.md) | [排序](/tags/sorting.md) | [单调栈](/tags/monotonic-stack.md)
