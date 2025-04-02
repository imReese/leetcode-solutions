# 2873. 有序三元组中的最大值 I (Maximum Value of an Ordered Triplet I)

[LeetCode 原题链接](https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/) | 难度: **简单** | 标签: `数组`

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

### 方法一: 暴力枚举

- 核心思想: 三层循环找出符合题目的三元组
- 时间复杂度: O(n³)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        long long num1 = nums[i];
                        long long num2 = nums[j];
                        long long num3 = nums[k];
                        res = max(res, ((num1 - num2) * num3));
                    }
                }
            }
            return res;
        }
};
```

### 方法二: 贪心

- 核心思想: 使用m记录下标j之前出现的最大值 然后双重遍历求符合题目的三元组 也可以左右遍历记录下标j两侧分别的最大值
- 时间复杂度: O(n²)
- 空间复杂度: O(1)

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for k in range(2, n):
            m = nums[0]
            for j in range(1, k):
                num1 = m
                num2 = nums[j]
                num3 = nums[k]
                res = max(res, ((num1 - num2) * num3))
                m = max(m, nums[j])
        return res
```

## 相似题目

- [2367. 等差三元组的数目](https://leetcode.cn/problems/number-of-arithmetic-triplets/)

## Tags

[数组](/tags/array.md)
