// Link: https://leetcode.cn/problems/solving-questions-with-brainpower/
// Level: Medium
// Date: 2025-04-01

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n + 1, 0);
            dp[n] = 0;
            for (int i = n - 1; i >= 0; i--) {
                long long points = questions[i][0];
                int skip = questions[i][1];
                int next = i + skip + 1 >= n ? n: i + skip + 1;
                dp[i] = max(points + dp[next], dp[i + 1]);
            }
            return dp[0];
        }
};