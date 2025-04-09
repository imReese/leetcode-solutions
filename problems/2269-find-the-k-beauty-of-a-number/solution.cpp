// Link: https://leetcode.cn/problems/find-the-k-beauty-of-a-number/
// Level: Easy
// Date: 2025-04-09

class Solution {
    public:
        int divisorSubstrings(int num, int k) {
            string s = to_string(num);
            int n = s.size();
            int res = 0;
            for (int i = 0; i < n - k + 1; i++) {
                int tmp = stoi(s.substr(i, k));
                if (tmp != 0 && num % tmp == 0) {
                    res++;
                }
            }
            return res;
        }
};