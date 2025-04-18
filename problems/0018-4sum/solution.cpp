// Link: https://leetcode.cn/problems/4sum/
// Level: Medium
// Date: 2025-02-25

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> quadruplets;
            if (nums.size() < 4) {
                return quadruplets;
            }
            sort(nums.begin(), nums.end());
            int length = nums.size();
            for(int i = 0; i < length - 3; i++) {
               if (i > 0 && nums[i] == nums[i - 1]) {
                   continue;
               }
               if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                   break;
               }
               if ((long)nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                   continue;
               }
               for (int j = i + 1; j < length - 2; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                        break;
                    }
                    if ((long)nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                        continue;
                    }
                    int left = j + 1, right = length - 1;
                    while (left < right) {
                        long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                        if (sum == target) {
                            quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                            while (left < right && nums[left] == nums[left + 1]) {
                                left++;
                            }
                            left++;
                            while (left < right && nums[right] == nums[right - 1]) {
                                right--;
                            }
                            right--;
                        } else if (sum < target) {
                            left++;
                        } else {
                            right--; 
                        }
                    }
               }
            }
            return quadruplets;
        }
};