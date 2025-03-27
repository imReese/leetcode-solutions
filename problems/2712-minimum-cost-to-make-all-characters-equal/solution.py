# Link: 
# Level: Medium
# Date: 2025-03-27

class Solution:
    def minimumCost(self, s: str) -> int:
        cost = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                cost += min(i, len(s) - i)
        return cost