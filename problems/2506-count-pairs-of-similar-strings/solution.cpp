// Link: https://leetcode.cn/problems/count-pairs-of-similar-strings/
// Level: Easy
// Date: 2025-02-22

class Solution {
    public:
        int similarPairs(vector<string>& words) {
            int res = 0;
            unordered_map<int, int> cnt;
            for (const string& word : words) {
                int state = 0;
                for (char c : word) {
                    state |= 1 << (c - 'a');
                }
                res += cnt[state];
                cnt[state]++;
            }
            return res;
        }
};