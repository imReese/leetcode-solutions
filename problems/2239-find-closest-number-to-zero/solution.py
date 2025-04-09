# Link: https://leetcode.cn/problems/find-closest-number-to-zero/
# Level: Easy
# Date: 2025-04-09

class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        return min(nums, key=lambda x: (abs(x), -x))
