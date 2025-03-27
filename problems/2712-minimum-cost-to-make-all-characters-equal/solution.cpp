// Link: https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/
// Level: Medium
// Date: 2025-03-27

class Solution {
    public:
        long long minimumCost(string s) {
            int len = s.size();
            long long cost = 0;
            for (int i = 1; i < len; i++) {
                if (s[i] != s[i - 1]) {
                    cost += min(i, len - i);
                }
            }
            return cost;
        }
};