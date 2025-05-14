// Link: https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/
// Level: Hard
// Date: 2025-05-14

const int MOD = 1e9 + 7;

class Solution {
public:
    using Matrix = vector<vector<int>>;

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> count(26, 0);
        for (char c : s)  {
            count[c - 'a']++;
        }

        Matrix M = buildMatrix(nums);
        Matrix mat = matrixPow(M, t);
        
        vector<long long> res(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) continue;
            for (int j = 0; j < 26; ++j) {
                res[j] = (res[j] + count[i] * mat[i][j]) % MOD;
            }
        }
        
        long long total = 0;
        for (long long x : res) {
            total = (total + x) % MOD;
        }
        return total;
    }

    Matrix buildMatrix(vector<int>& nums) {
        Matrix M(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < nums[i]; ++k) {
                int j = (i + 1 + k) % 26;
                M[i][j]++;
            }
        }
        return M;
    }
    
    Matrix matrixPow(Matrix base, int power) {
        Matrix res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) res[i][i] = 1;
        
        while (power > 0) {
            if (power & 1) res = multiply(res, base);
            base = multiply(base, base);
            power >>= 1;
        }
        return res;
    }
    
    Matrix multiply(Matrix& a, Matrix& b) {
        Matrix res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    res[i][j] = (res[i][j] + (long long)a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return res;
    }
};
