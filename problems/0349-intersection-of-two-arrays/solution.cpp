// Link: https://leetcode.cn/problems/intersection-of-two-arrays/
// Level: Easy
// Date: 2025-03-29

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            unordered_set<int> set1(nums1.begin(), nums1.end());
            unordered_set<int> set2(nums2.begin(), nums2.end());
            for (auto num : set1) {
                if (set2.find(num) != set2.end()) {
                    res.push_back(num);
                }
            }
            return res;
        }
};