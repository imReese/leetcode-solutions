# Link: https://leetcode.cn/problems/percentage-of-letter-in-string/
# Level: Easy
# Date: 2025-03-31

class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        cnt = 0
        for ch in s:
            if ch == letter:
                cnt += 1
        return (100 * cnt // len(s))