// Link: https://leetcode.cn/problems/count-number-of-bad-pairs/
// Level: Medium
// Date: 2025-04-18

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long ans = 0;
            int n = nums.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++) {
                ans += i - mp[nums[i] - i];
                mp[nums[i] - i]++;
            }
            return ans;
        }
};
