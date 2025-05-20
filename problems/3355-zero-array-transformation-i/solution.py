# Link: https://leetcode.cn/problems/zero-array-transformation-i/
# Level: Medium
# Date: 2025-05-20

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        diff = [0] * (n + 2)

        for l, r in queries:
            diff[l] += 1
            if r + 1 < n + 1:
                diff[r + 1] -= 1
        
        prefix = 0
        for i in range(n):
            prefix += diff[i]
            if nums[i] < 0 or prefix < nums[i]:
                return False
        return True
