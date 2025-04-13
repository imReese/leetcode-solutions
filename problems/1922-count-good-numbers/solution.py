# Link: https://leetcode.cn/problems/count-good-numbers/
# Level: Medium
# Date: 2025-04-13

class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 10**9 + 7

        def quickmul(x: int, y: int) -> int:
            ret, mul = 1, x
            while y > 0:
                if y % 2 == 1:
                    ret = ret * mul % mod
                mul = mul * mul % mod
                y //= 2
            return ret
        
        return quickmul(5, (n + 1) // 2) * quickmul(4, n // 2) % mod
