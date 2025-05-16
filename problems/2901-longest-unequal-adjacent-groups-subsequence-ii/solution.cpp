// Link: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/
// Level: Medium
// Date: 2025-05-16

class Solution {
private:
    bool isAdjacent(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int max_len = 1;
        int max_idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && isAdjacent(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_idx = i;
            } else if (dp[i] == max_len) {
                max_idx = i;
            }
        }

        vector<int> path;
        int curr = max_idx;
        while (curr != -1) {
            path.push_back(curr);
            curr = prev[curr];
        }
        reverse(path.begin(), path.end());
        vector<string> res;
        for (int i : path) {
            res.push_back(words[i]);
        }
        return res;
    }
};
