# Link: https://leetcode.cn/problems/count-the-number-of-ideal-arrays/
# Level: Hard
# Date: 2025-04-23

MOD = 10**9 + 7

class Solution:
    def sieve(self, n: int) -> list:
        min_prime = [0] * (n + 1)
        for i in range(2, n + 1):
            if min_prime[i] == 0:
                min_prime[i] = i
                for j in range(i * i, n + 1, i):
                    if min_prime[j] == 0:
                        min_prime[j] = i
        return min_prime

    def idealArrays(self, n: int, maxValue: int) -> int:
        if maxValue < 1:
            return 0

        min_prime = self.sieve(maxValue)

        max_k = maxValue + n
        fact = [1] * (max_k + 1)
        for i in range(1, max_k + 1):
            fact[i] = (fact[i - 1] * i) % MOD
        inv_fact = [1] * (max_k + 1)
        inv_fact[max_k] = pow(fact[max_k], MOD - 2, MOD)
        for i in range(max_k - 1, -1, -1):
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD

        ans = 0
        for v in range(1, maxValue + 1):
            if v == 1:
                ans = (ans + 1) % MOD
                continue

            factors = {}
            x = v
            while x > 1:
                p = min_prime[x]
                cnt = 0
                while x % p == 0:
                    cnt += 1
                    x = x // p
                factors[p] = factors.get(p, 0) + cnt

            contribution = 1
            for e in factors.values():
                a = e + n - 1
                if a > max_k:
                    return -1
                # C(a, e) = fact[a] * inv_fact[e] * inv_fact[a-e] % MOD
                c = fact[a] * inv_fact[e] % MOD
                c = c * inv_fact[n - 1] % MOD
                contribution = contribution * c % MOD
            ans = (ans + contribution) % MOD
        return ans % MOD
