# Link: https://leetcode.cn/problems/palindrome-partitioning-iii/
# Level: Hard
# Date: 2025-04-04

class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        def cost(l, r):
            cnt = 0
            while l < r:
                if s[l] != s[r]:
                    cnt += 1
                l += 1
                r -= 1
            return cnt

        n = len(s)
        dp = [[10**9] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, min(i, k) + 1):
                if j == 1:
                    dp[i][j] = cost(0, i - 1)
                else:
                    for p in range(j - 1, i):
                        dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost(p, i - 1))

        return dp[n][k]