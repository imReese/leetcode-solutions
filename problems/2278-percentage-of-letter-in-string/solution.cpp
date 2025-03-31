// Link: https://leetcode.cn/problems/percentage-of-letter-in-string/
// Level: Easy
// Date: 2025-03-31

class Solution {
    public:
        int percentageLetter(string s, char letter) {
            int cnt = 0;
            for (char ch : s) {
                if (ch == letter) {
                    cnt++;
                }
            }
            return (100 * cnt / s.size());
        }
};