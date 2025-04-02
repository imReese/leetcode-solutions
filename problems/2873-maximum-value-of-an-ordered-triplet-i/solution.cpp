// Link: https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/
// Level: Easy
// Date: 2025-04-02

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        long long num1 = nums[i];
                        long long num2 = nums[j];
                        long long num3 = nums[k];
                        res = max(res, ((num1 - num2) * num3));
                    }
                }
            }
            return res;
        }
};