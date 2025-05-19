// Link: https://leetcode.cn/problems/target-sum/
// Level: Medium
// Date: 2025-05-19

class Solution {
private:
    int backtrack(vector<int>& nums, int target, int idx, int curr_sum) {
        int n = nums.size();
        if (idx == n) {
            return curr_sum == target ? 1 : 0;
        }
        return backtrack(nums, target, idx + 1, curr_sum + nums[idx]) +
            backtrack(nums, target, idx + 1, curr_sum - nums[idx]);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = backtrack(nums, target, 0, 0);
        return res;
    }
};
