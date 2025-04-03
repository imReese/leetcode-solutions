# https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/
# Level: Medium
# Date: 2025-04-03

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        imax = 0
        dmax = 0
        for k in range(n):
            res = max(res, dmax * nums[k])
            dmax = max(dmax, imax - nums[k])
            imax = max(imax, nums[k])
        return res