// Link: https://leetcode.cn/problems/adding-spaces-to-a-string/
// Level: Medium
// Date: 2025-03-30

class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
            int m = s.size();
            int n = spaces.size();
            string res = "";
            int i = 0;
            int j = 0;
            while(i < m && j < n) {
                if(i == spaces[j]) {
                    res += " ";
                    j++;
                } else {
                    res += s[i];
                    i++;
                }
            }
            while(i < m) {
                res += s[i];
                i++;
            }
            return res;
        }
};
