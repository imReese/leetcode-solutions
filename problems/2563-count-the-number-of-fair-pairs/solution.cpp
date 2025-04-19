// Link: https://leetcode.cn/problems/count-the-number-of-fair-pairs/
// Level: Medium
// Date: 2025-04-19

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            long long res = 0;
            sort(nums.begin(), nums.end());
            for (int j = 0; j < nums.size(); j++) {
                auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
                auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
                res += r - l;
            }
            return res;
        }
};
