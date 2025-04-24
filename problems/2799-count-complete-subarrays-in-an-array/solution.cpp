// Link: https://leetcode.cn/problems/count-complete-subarrays-in-an-array/
// Level: Medium 
// Date: 2025-04-24

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int res = 0;
            int n = nums.size();
            unordered_set<int> distinct(nums.begin(), nums.end());
            int distinct_count = distinct.size();
    
            int right = 0;
            unordered_map<int, int> cnt;
            for (int left = 0; left < n; left++) {
                if (left > 0) {
                    int remove = nums[left - 1];
                    cnt[remove]--;
                    if (cnt[remove] == 0) {
                        cnt.erase(remove);
                    }
                }
                while (right < n && cnt.size() < distinct_count) {
                    int add = nums[right];
                    cnt[add]++;
                    right++;
                }
                if (cnt.size() == distinct_count) {
                    res += (n - right + 1);
                }
            }
    
            return res;
        }
};
