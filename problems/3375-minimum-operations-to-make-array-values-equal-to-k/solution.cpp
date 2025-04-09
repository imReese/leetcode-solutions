// Link: https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/
// Level: Easy
// Date: 2025-04-09

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n = nums.size();
            int res = -1;
            unordered_set<int> s;
            for (auto num : nums) {
                if (num < k) {
                    return -1;
                } else if (num > k) {
                    s.insert(num);
                }
            }
            res = s.size();
            return res;
        }
};