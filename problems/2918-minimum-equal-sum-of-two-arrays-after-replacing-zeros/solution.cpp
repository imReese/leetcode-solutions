// Link: https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
// Level: Medium
// Date: 2025-05-10

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, zero1 = 0;
        for (int num : nums1) {
            if (num == 0) {
                zero1++;
            }
            sum1 += num;
        }
        long long sum2 = 0, zero2 = 0;
        for (int num : nums2) {
            if (num == 0) {
                zero2++;
            }
            sum2 += num;
        }
        long long s1 = sum1 + zero1;
        long long s2 = sum2 + zero2;
        if (zero1 == 0 && zero2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        } else if (zero1 == 0) {
            return (sum1 >= s2) ? sum1 : -1;
        } else if (zero2 == 0) {
            return (sum2 >= s1) ? sum2 : -1;
        } else {
            return max(s1, s2);
        }
    }
};
