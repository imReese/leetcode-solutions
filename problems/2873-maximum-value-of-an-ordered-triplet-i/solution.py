# Link: https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/
# Level: Easy
# Date: 2025-04-02

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