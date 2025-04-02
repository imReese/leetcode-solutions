# Link: https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-i/
# Level: Hard
# Date: 2025-04-02

class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        mod = 10 ** 9 + 7
        n = len(nums)
        m = max(nums)
        dp = [[0] * (m + 1) for _ in range(n)]
        for a in range(nums[0] + 1):
            dp[0][a] = 1
        for i in range(1, n):
            d = max(0, nums[i] - nums[i - 1])
            for j in range(d, nums[i] + 1):
                if j == 0:
                    dp[i][j] = dp[i - 1][j - d]
                else:
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - d]) % mod
        return sum(dp[n - 1]) % mod