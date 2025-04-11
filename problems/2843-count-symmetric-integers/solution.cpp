// Link: https://leetcode.cn/problems/count-symmetric-integers/
// Level: Easy
// Date: 2025-04-11

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res = 0;
            for (int a = low; a <= high; a++) {
                if (a < 100 && a % 11 == 0) {
                    res++;
                } else if (a >= 1000 && a < 10000) {
                    int left = a / 1000 + (a % 1000) / 100;
                    int right = (a % 100) / 10 + a % 10;
                    if (left == right) {
                        res++;
                    }
                }
            }
            return res;
        }
};
