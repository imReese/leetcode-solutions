// Link: https://leetcode.cn/problems/sum-of-all-subset-xor-totals/
// Level: Easy
// Date: 2025-04-06

class Solution {
    public:
        int res;
        int n;
    
        void dfs(int val, int idx, vector<int>& nums) {
            if (idx == n) {
                res += val;
                return;
            }
    
            // 考虑选择当前数字
            dfs(val ^ nums[idx], idx + 1, nums);
            // 考虑不选择当前数字
            dfs(val, idx + 1, nums);
        }
    
        int subsetXORSum(vector<int>& nums) {
            res = 0;
            n = nums.size();
            dfs(0, 0, nums);
            return res;        
        }
};