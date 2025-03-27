// Link: https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/
// Level: Medium
// Date: 2025-03-26

class Solution {
    public:
        int minimumSum(int n, int k) {
            int res = 0;
            unordered_set<int> nums;
            int num = 1;
            while (nums.size() < n) {
                if (nums.find(k - num) == nums.end()) {
                    nums.insert(num);
                    res += num;
                }
                num++;
            }
            return res;
        }
};