# Link: https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/
# Level: Medium
# Date: 2025-03-30

class Solution:
    def minSwaps(self, s: str) -> int:
        ans = 0
        cnt = 0
        for c in s:
            if c == '[':
                cnt += 1
            else:
                if cnt > 0:
                    cnt -= 1
                else:
                    ans += 1
        return (ans + 1) // 2