// Link: https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
// Level: Easy
// Date: 2025-04-08

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int res = 0;
            int n = nums.size();
            unordered_set<int> s;
            for (int i = n - 1; i >= 0; i--) {
                if (s.find(nums[i]) != s.end()) {
                    res = i / 3 + 1;
                    break;
                }
                s.insert(nums[i]);
            }
            return res;
        }
};