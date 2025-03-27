// Link: https://leetcode.cn/problems/x-of-a-kind-in-a-deck-of-cards/
// Level: Easy
// Date: 2025-02-22

class Solution {
    public:
        bool hasGroupsSizeX(vector<int>& deck) {
            unordered_map<int, int> cnt;
            for (int i : deck) {
                cnt[i]++;
            }

            int x = 0;
            for (const auto& pair : cnt) {
                x = gcd(x, pair.second); 
            }
            return x >= 2;
        }
};