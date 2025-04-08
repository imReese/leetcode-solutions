// Link: https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/
// Level: Medium
// Date: 2025-04-08

class Solution {
    public:
        int minimumSubarrayLength(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> bits(30);
            auto calc = [](vector<int>& bits) -> int {
                int ans = 0;
                for (int i = 0; i < bits.size(); i++) {
                    if (bits[i] > 0) {
                        ans |= 1 << i;
                    }
                }
                return ans;
            };

            int res = INT_MAX;
            for (int left = 0, right = 0; right < n; right++) {
                for (int i = 0; i < 30; i++) {
                    bits[i] += (nums[right] >> i) & 1;
                }
                while (left <= right && calc(bits) >= k) {
                    res = min(res, right - left + 1);
                    for (int i = 0; i < 30; i++) {
                        bits[i] -= (nums[left] >> i) & 1;
                    }
                    left++;
                }
            }

            return res == INT_MAX ? -1: res;
        }
};