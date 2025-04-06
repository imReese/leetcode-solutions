# Link: https://leetcode.cn/problems/largest-divisible-subset/
# Level: Medium
# Date: 2025-04-06

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        dp = [1] * n
        nums.sort()
        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[i], dp[j] + 1)
        maxSize = max(dp)
        res = []
        current_size = max_size
        for i in reversed(range(n)):
            if current_size <= 0:
                break
            if dp[i] == current_size:
                if not res or res[-1] % nums[i] == 0:
                    res.append(nums[i])
                    current_size -= 1
        res.reverse()
        return res
        