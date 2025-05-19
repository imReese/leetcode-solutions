# Link: https://leetcode.cn/problems/target-sum/
# Level: Medium
# Date: 2025-05-19

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = sum(nums)
        if (total - target) < 0 or (total - target) % 2 != 0:
            return 0
        neg = (total - target) // 2
        dp = [0] * (neg + 1)
        dp[0] = 1
        for num in nums:
            for j in range(neg, num - 1, -1):
                dp[j] += dp[j - num]
        return dp[neg]
