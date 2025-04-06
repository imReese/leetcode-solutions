// Link: https://leetcode.cn/problems/largest-divisible-subset/
// Level: Medium
// Date: 2025-04-06

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int len = nums.size();

            vector<vector<int>> dp(len, vector<int>());
            sort(nums.begin(), nums.end());

            int maxLen = 1;
            dp[0] = vector<int>(1, nums[0]);
            vector<int> res = dp[0];
            for (int i = 1; i < len; i++) {
                dp[i].push_back(nums[i]);
                for (int j = i - 1; j >= 0; j--) {
                    if (nums[i] % nums[j] == 0) {
                        if (dp[j].size() + 1 > dp[i].size()) {
                            dp[i] = dp[j];
                            dp[i].push_back(nums[i]);
                        }
                    }
                }
                if (dp[i].size() > maxLen) {
                    maxLen = dp[i].size();
                    res = dp[i];
                }
            }
            return res;
        }
};