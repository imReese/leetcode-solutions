# Link: https://leetcode.cn/problems/count-the-number-of-fair-pairs/
# Level: Medium
# Date: 2025-04-19

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        res = 0
        for j, x in enumerate(nums):
            r = bisect_right(nums, upper - x, 0, j)
            l = bisect_left(nums, lower - x, 0, j)
            res += r - l
        return res
