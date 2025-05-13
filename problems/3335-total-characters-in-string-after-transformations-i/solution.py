# Link: https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/
# Level: Medium
# Date: 2025-05-13

MOD = 10**9 + 7

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        
        prev = [1] * 26
        for _ in range(t):
            curr = [0] * 26
            for c in range(26):
                if c != 25:
                    curr[c] = prev[c+1] % MOD
                else:
                    curr[c] = (prev[0] + prev[1]) % MOD
            prev = curr

        res = sum(cnt[i] * prev[i] for i in range(26)) % MOD
        return int(res)
