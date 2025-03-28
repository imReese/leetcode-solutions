// Link:https://leetcode.cn/problems/minimize-string-length/
// Level: Easy
// Date: 2025-03-28

class Solution {
    public:
        int minimizedStringLength(string s) {
            int res = 0;
            unordered_set<char> set;
            for (char c : s) {
                if (set.find(c) == set.end()) {
                    set.insert(c);
                    res++;
                }
            }
            return res;
        }
};