# Link: https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
# Level: Hard
# Date: 2025-04-13

class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        mod = 10**9 + 7

        # 计算 m^n
        def quickmul(m, n):
            ret = 1
            mul = m
            while n > 0:
                if n % 2 == 1:
                    ret = ret * mul % mod
                mul = mul * mul % mod
                n //= 2
            return ret

        # 计算总数量
        total = comb(n - 1, k) * quickmul(m - 1, n - 1 - k) * m % mod

        return total
