# Link: https://leetcode.cn/problems/find-the-k-beauty-of-a-number/
# Level: Easy
# Date: 2025-04-09

class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        n = len(s)
        res = 0
        for i in range(n - k + 1):
            tmp = int(s[i:i+k])
            if tmp != 0 and num % tmp == 0:
                res += 1
        return res