// Link: https://leetcode.cn/problems/sum-of-square-numbers/
// Level: Medium
// Date: 2025-03-31

class Solution {
    public:
        bool judgeSquareSum(int c) {
            long left = 0;
            long right = (int)sqrt(c);
            while (left <= right) {
                long sum = left * left + right * right;
                if (sum == c) {
                    return true;
                } else if (sum < c) {
                    left++;
                } else if (sum > c) {
                    right--;
                }
            }
            return false;
        }
};