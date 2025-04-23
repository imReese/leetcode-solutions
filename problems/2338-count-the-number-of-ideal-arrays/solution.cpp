// Link: https://leetcode.cn/problems/count-the-number-of-ideal-arrays/
// Level: Hard
// Date: 2025-04-23

const int MOD = 1e9 + 7;

class Solution {
    private:
        vector<int> sieve(int n) {
            vector<int> min_prime(n + 1, 0);
            for (int i = 2; i <= n; i++) {
                if (min_prime[i] == 0) {
                    min_prime[i] = i;
                    for (int j = 2 * i; j <= n; j += i) {
                        if (min_prime[j] == 0) {
                            min_prime[j] = i;
                        }
                    }
                }
            }
            return min_prime;
        }

        int pow_mod(int a, int b, int mod) {
            int res = 1;
            while (b > 0) {
                if (b & 1) {
                    res = (long long)res * a % mod;
                }
                a = (long long)a * a % mod;
                b >>= 1;
            }
            return res;
        }
    public:
        int idealArrays(int n, int maxValue) {
            if (maxValue < 1) {
                return 0;
            }
            vector<int> min_prime = sieve(maxValue);

            int max_k = maxValue + n;
            vector<int> fact(max_k + 1, 1);
            vector<int> inv_fact(max_k + 1, 1);

            for (int i = 1; i <= max_k; i++) {
                fact[i] = (long long)fact[i - 1] * i % MOD;
            }
            inv_fact[max_k] = pow_mod(fact[max_k], MOD - 2, MOD);
            for (int i = max_k - 1; i >= 0; i--) {
                inv_fact[i] = (long long)inv_fact[i + 1] * (i + 1) % MOD;
            }

            long long ans = 0;
            for (int v = 1; v <= maxValue; v++) {
                if (v == 1) {
                    ans = (ans + 1) % MOD;
                    continue;
                }
                unordered_map<int, int> factors;
                int x = v;
                while (x > 1) {
                    int p = min_prime[x];
                    int cnt = 0;
                    while (x % p == 0) {
                        cnt++;
                        x /= p;
                    }
                    factors[p] = cnt;
                }

                long long contribution = 1;
                for (auto& [p, e] : factors) {
                    int k = e + n - 1;
                    if (k > max_k) {
                        return - 1;
                    }
                    long long c = (long long)fact[k] * inv_fact[n - 1] % MOD;
                    c = c * inv_fact[k - (n - 1)] % MOD;
                    contribution = contribution * c % MOD;
                }
                ans = (ans + contribution) % MOD;
            }
            return ans % MOD;
        }
};
