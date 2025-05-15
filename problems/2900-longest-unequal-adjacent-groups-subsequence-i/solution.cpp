// Link: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/
// Level: Easy
// Date: 2025-05-15

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        if (n == 0) {
            return {};
        }

        vector<int> path0, path1;
        int len0 = 0, len1 = 0;

        if (groups[0] == 0) {
            path0.push_back(0);
            len0 = 1;
        } else {
            path1.push_back(0);
            len1 = 1;
        }

        for (int i = 1; i < n; ++i) {
            int g = groups[i];
            if (g == 0) {
                vector<int> new_path = path0;
                int new_len = len0;
                if (len1 + 1 > len0) {
                    new_len = len1 + 1;
                    new_path = path1;
                    new_path.push_back(i);
                }
                if (new_len > len0) {
                    len0 = new_len;
                    path0 = new_path;
                }
            } else {
                vector<int> new_path = path1;
                int new_len = len1;
                if (len0 + 1 > len1) {
                    new_len = len0 + 1;
                    new_path = path0;
                    new_path.push_back(i);
                }
                if (new_len > len1) {
                    len1 = new_len;
                    path1 = new_path;
                }
            }
        }

        vector<string> res;
        if (len0 >= len1) {
            for (int idx : path0) res.push_back(words[idx]);
        } else {
            for (int idx : path1) res.push_back(words[idx]);
        }
        return res;
    }
};
