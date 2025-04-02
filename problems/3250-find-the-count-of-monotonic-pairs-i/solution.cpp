// Link: https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-i/
// Level: Hard
// Date: 2025-04-02


// 对于唯一的arr1有唯一确定的arr2
// dp[i][j]表示当arr1[i] = j时 nums中前i+1个元素组成的单调数组的数目
class Solution {
    public:
        int countOfPairs(vector<int>& nums) {
            int n = nums.size();
            int m = *max_element(nums.begin(), nums.end());
            int mod = 1e9 + 7;
            int res = 0;
            vector<vector<int>> dp(n, vector<int>(m + 1, 0));
            for (int j = 0; j <= nums[0]; j++) {
                dp[0][j] = 1;
            }
            for (int i = 1; i < n; i++) {
                int d = max(0, nums[i] - nums[i - 1]);
                for (int j = d; j <= nums[i]; j++) {
                    if (j == 0) {
                        dp[i][j] = dp[i - 1][j - d];
                    } else {
                        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - d]) % mod;
                    }
                }
            }
            for (int num: dp[n - 1]) {
                res = (res + num) % mod;
            }
            return res;
        }
};