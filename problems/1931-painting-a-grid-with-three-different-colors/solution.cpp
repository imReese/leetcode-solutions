// Link: https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/
// Level: Hard
// Date: 2025-05-18

const int MOD = 1e9 + 7;

class Solution {
private:
    bool isValidColumn(int s, int m) {
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            int color = s % 3;
            if (color == prev) return false;
            prev = color;
            s /= 3;
        }
        return true;
    }
    
    bool canTransfer(int s1, int s2, int m) {
        for (int i = 0; i < m; ++i) {
            if (s1 % 3 == s2 % 3) return false;
            s1 /= 3;
            s2 /= 3;
        }
        return true;
    }

public:
    int colorTheGrid(int m, int n) {
        vector<int> valid_states;
        for (int s = 0; s < pow(3, m); s++) {
            if (isValidColumn(s, m)) {
                valid_states.emplace_back(s);
            }
        }
        int k = valid_states.size();
        if (k == 0) {
            return 0;
        }

        unordered_map<int, vector<int>> transitions;
        unordered_map<int, int> state_to_index;
        for (int i = 0; i < k; i++) {
            state_to_index[valid_states[i]] = i;
        }

        for (int s1 : valid_states) {
            for (int s2 : valid_states) {
                if (canTransfer(s1, s2, m)) {
                    transitions[s1].emplace_back(s2);
                }
            }
        }

        vector<long long> dp_prev(k, 1);
        for (int col = 1; col < n; col++) {
            vector<long long> dp_curr(k, 0);
            for (int i = 0; i < k; i++) {
                int s1 = valid_states[i];
                for (int s2 : transitions[s1]) {
                    int j = state_to_index[s2];
                    dp_curr[j] = (dp_curr[j] + dp_prev[i]) % MOD;
                }
            }
            dp_prev = dp_curr;
        }
        long long res = 0;
        for (int i = 0; i < k; i++) {
            res = (res + dp_prev[i]) % MOD;
        }
        return res;
    }
};
