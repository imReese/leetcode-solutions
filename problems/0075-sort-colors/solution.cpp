// Link: https://leetcode.cn/problems/sort-colors/
// Level: Medium
// Date: 2025-05-17

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p1]);
                p1++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;
            }
        }
    }
};
