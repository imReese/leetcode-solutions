// Link: https://leetcode.cn/problems/candy/
// Level: Hard
// Date: 2025-04-20

class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> left(n);
            for (int i = 0; i < n; i++) {
                if (i > 0 && ratings[i] > ratings[i - 1]) {
                    left[i] = left[i - 1] + 1;
                } else {
                    left[i] = 1;
                }
            }
            vector<int> right(n);
            for (int i = n - 1; i >= 0; i--) {
                if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                    right[i] = right[i + 1] + 1;
                } else {
                    right[i] = 1;
                }
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += max(left[i], right[i]);
            }
            return res;
        }
};
