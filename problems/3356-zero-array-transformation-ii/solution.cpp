// Link: https://leetcode.cn/problems/zero-array-transformation-ii/
// Level: Medium
// Date: 2025-05-21

class Solution {
private:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> pre(n + 2, 0);

        for (int i = 0; i < k; ++i) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            pre[l] -= val;
            if (r + 1 < n) {
                pre[r + 1] += val;
            }
        }

        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum += pre[i];
            if (nums[i] + prefixSum > 0) {
                return false;
            }
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int left = -1, right = m + 1;

        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (check(nums, queries, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right <= m ? right : -1;
    }
};
