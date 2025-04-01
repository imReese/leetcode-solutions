# Link: https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
# Level: Easy
# Date: 2025-04-01

class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')