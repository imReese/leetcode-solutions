// Link: https://leetcode.cn/problems/find-closest-number-to-zero/
// Level: Easy
// Date: 2025-04-09

class Solution {
    public:
        int findClosestNumber(vector<int>& nums) {
            int res = INT_MAX;
            for (int num : nums) {
                if (abs(num) < abs(res) || (abs(num) == abs(res) && num > res)) {
                    res = num;
                }
            }
            return res;
        }
};