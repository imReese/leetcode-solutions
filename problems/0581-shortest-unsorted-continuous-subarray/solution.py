# Link: https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/
# Level: Medium
# Date: 2025-05-11

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        maxn, minn = float("-inf"), float("inf")
        right, left = -1, -1
        for i in range(n):
            if nums[i] >= maxn:
                maxn = nums[i]
            else:
                right = i
            if nums[n - i - 1] <= minn:
                minn = nums[n - i - 1]
            else:
                left = n - i - 1
        return 0 if right == -1 else right - left + 1
