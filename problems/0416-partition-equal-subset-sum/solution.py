# Link: https://leetcode.cn/problems/partition-equal-subset-sum/
# Level: Medium
# Date: 2025-04-08

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        total = sum(nums)
        if total % 2 == 1:
            return False
        target = total // 2
        maxNum = max(nums)
        if maxNum > target:
            return False
        dp = [False] * (target + 1)
        dp[0] = True
        for i in range(n):
            num = nums[i]
            for j in range(target, num - 1, -1):
                dp[j] |= dp[j - num]
        return dp[target]