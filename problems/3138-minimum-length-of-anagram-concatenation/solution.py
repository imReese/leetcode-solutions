# Link: https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/
# Level: Medium
# Date: 2025-04-06

class Solution:
    def minAnagramLength(self, s: str) -> int:
        n = len(s)
        def check(m: int) -> bool:
            for j in range (m, n, m):
                if Counter(s[:m] != Counter(s[j:j+m])):
                    return False
            return True
        for i in range(1, n):
            if n % i != 0:
                continue
            if check(i):
                return i
        return n