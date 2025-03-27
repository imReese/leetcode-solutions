// Link: https://leetcode-cn.com/problems/two-sum/
// Level: Easy
// Date: 2025-03-26

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            unordered_map<int, int> hash_map;
            for (int i = 0; i < nums.size(); i++) {
                if (hash_map.find(target - nums[i]) == hash_map.end()) {
                    hash_map[nums[i]] = i;
                } else {
                    res.push_back(hash_map[target - nums[i]]);
                    res.push_back(i);
                    break;
                }
            }
            return res;
        }
};