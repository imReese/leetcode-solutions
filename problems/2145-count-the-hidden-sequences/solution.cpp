// Link: https://leetcode.cn/problems/count-the-hidden-sequences/
// Level: Medium
// Date: 2025-04-21

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int num = 0;
            int min_num = 0;
            int max_num = 0;
            for (int d : differences) {
                num += d;
                min_num = min(num, min_num);
                max_num = max(num, max_num);
                if (max_num - min_num > upper - lower) {
                    return 0;
                }
            }
            int res = (upper - lower) - (max_num - min_num) + 1;
            return res;
        }
};
