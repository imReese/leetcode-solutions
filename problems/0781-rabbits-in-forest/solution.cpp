// Link: https://leetcode.cn/problems/rabbits-in-forest/
// Level: Medium
// Date: 2025-04-20

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int res = 0;
            unordered_map<int, int> cnt;
            for (int ans : answers) {
                if (cnt[ans] == 0) {
                    res += ans + 1;
                }
                cnt[ans]++;
                if (cnt[ans] == ans + 1) {
                    cnt[ans] = 0;
                }
            }
            return res;
        }
};
