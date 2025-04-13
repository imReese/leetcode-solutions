// Link: https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
// Level: Hard
// Date: 2025-04-13

class Solution {
    private:
        static constexpr int mod = 1000000007;
    public:
        int countGoodArrays(int n, int m, int k) {
            auto quickmul = [](int x, long long y) -> int {
                int ret = 1, mul = x;
                while (y > 0) {
                    if (y % 2 == 1) {
                        ret = (long long)ret * mul % mod;
                    }
                    mul = (long long)mul * mul % mod;
                    y /= 2;
                }
                return ret;
            };

            auto comb = [&](long long n, long long k) -> long long { // 使用[&]捕获quickmul
                if (k > n) {
                    return 0;
                }
                if (k == 0 || k == n) {
                    return 1;
                }
                k = min(k, n - k);
                int ret = 1;
                for (int i = 1; i <= k; i++) {
                    ret = (long long)ret * (n - i + 1) % mod;
                    ret = (long long)ret * quickmul(i, mod - 2) % mod; // 使用逆元
                }
                return ret % mod;
            };

            int res = (long long)comb(n - 1, k) % mod;
            res = (long long)res * quickmul(m - 1, n - 1 - k) % mod;
            res = (long long)res * m % mod;
            return res;
        }
};
