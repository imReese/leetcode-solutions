// Link: https://leetcode.cn/problems/number-of-even-and-odd-bits/
// Level: Easy
// Date: 2025-02-20

class Solution {
    public:
        vector<int> evenOddBit(int n) {
            vector<int> res(2, 0);
            int index = 0;
            while(n) {
                if (n & 1) {
                    res[index % 2]++;
                }
                n >>= 1;
                index++;
            }
            return res;
        }
};