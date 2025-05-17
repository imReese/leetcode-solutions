# Link: https://leetcode.cn/problems/sort-colors/
# Level: Medium
# Date: 2025-05-17

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p0, p1 = 0, 0
        n = len(nums)
        for i, num in enumerate(nums):
            if num == 1:
                nums[p1], nums[i] = nums[i], nums[p1]
                p1 += 1
            elif num == 0:
                nums[p0], nums[i] = nums[i], nums[p0]
                if p0 < p1:
                    nums[p1], nums[i] = nums[i], nums[p1]
                p0 += 1
                p1 += 1
