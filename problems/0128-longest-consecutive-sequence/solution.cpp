// Link: https://leetcode.cn/problems/longest-consecutive-sequence/
// Level: Medium
// Date: 2025-05-10

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_len = 0;
        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int current = num, current_len = 1;
                while (num_set.count(current + 1)) {
                    current++;
                    current_len++;
                }
                max_len = max(max_len, current_len);
            }
        }
        return max_len;
    }
};
