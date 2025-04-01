// Link: https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
// Level: Easy
// Date: 2025-04-01

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int cnt = 0;
            while(n) {
                cnt += n&1;
                n >>= 1;
            }
            return cnt;
        }
};