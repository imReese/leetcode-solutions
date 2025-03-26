// Link: https://leetcode.cn/problems/3sum/
// Level: Medium
// Date: 2025-02-25

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> triplets;
            if (nums.size() < 3) {
                return triplets;
            }
            sort(nums.begin(), nums.end());
            int length = nums.size();
            for (int i = 0; i < length - 2; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
                    break;
                }
                if (nums[i] + nums[length - 2] + nums[length - 1] < 0) {
                    continue;
                }
                int left = i + 1, right = length - 1;
                while (left < right) {
                    long sum = (long)nums[i] + nums[left] + nums[right];
                    if (sum == 0) {
                        triplets.push_back({nums[i], nums[left], nums[right]}); 
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < 0) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
            return triplets;
        }
};