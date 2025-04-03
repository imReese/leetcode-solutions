// https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/
// Level: Medium
// Date: 2025-04-03

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            vector<int> leftMax(n, 0);    // leftMax[i]记录nums中0-(i-1)之间的最大值
            vector<int> rightMax(n, 0);   // rightMax[j]记录nums中(j+1)-(n-1)之间的最大值
            leftMax[0] = nums[0];
            rightMax[n - 1] = nums[n - 1];
            for (int i = 1; i < n; i++) {
                leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
                rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
            }
            for (int i = 1; i < n - 1; i++) {
                res = max(res, (long long)(leftMax[i] - nums[i]) * rightMax[i]);
            }
            return res;
        }
};