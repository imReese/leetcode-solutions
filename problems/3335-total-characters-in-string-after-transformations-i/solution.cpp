// Link: https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/
// Level: Medium
// Date: 2025-05-13

const int MOD = 1e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26, 0);
        for (char& c : s) {
            cnt[c - 'a']++;
        }

        vector<long long> prev(26, 1);
        for (int k = 1; k <= t; k++) {
            vector<long long> curr(26, 0);
            for (int c = 0; c < 26; c++) {
                if (c != 25) {
                    current[c] = prev[c+1] % MOD;
                } else {
                    current[c] = (prev[0] + prev[1]) % MOD;
                }
            }
            prev = curr;
        }
        long long res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + cnt[i] * prev[i]) % MOD;
        }
        return res;
    }
};
