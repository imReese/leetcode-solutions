// Link: https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/
// Level: Medium
// Date: 2025-03-30

class Solution {
    public:
        int minSwaps(string s) {
            int res = 0;
            int count = 0;
            for(char c : s) {
                if(c == '[') {
                    count++;
                } else {
                    if(count > 0) {
                        count--;
                    } else {
                        res++;
                    }
                }
            }
            return (res + 1) / 2;
        }
};