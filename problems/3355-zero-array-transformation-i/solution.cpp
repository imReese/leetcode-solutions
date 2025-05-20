// Link: https://leetcode.cn/problems/zero-array-transformation-i/
// Level: Medium
// Date: 2025-05-20

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 2, 0);

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l]++;
            if (r + 1 < n) {
                diff[r+1]--;
            }
        }

        int prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += diff[i];
            if (nums[i] < 0 || prefix < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
