// Link: https://leetcode.cn/problems/count-largest-group/
// Level: Easy
// Date: 2025-04-23

class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> mp;
            int maxSum = 0;
            for (int i = 1; i <= n; i++) {
                int key = 0, i0 = i;
                while (i0 > 0) {
                    key += i0 % 10;
                    i0 /= 10;
                }
                mp[key]++;
                maxSum = max(maxSum, mp[key]);
            }
            int ans = 0;
            for (auto& kvpair : mp) {
                if (kvpair.second == maxSum) {
                    ans++;
                }
            }
            return ans;
        }
};
