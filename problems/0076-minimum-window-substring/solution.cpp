// Link: https://leetcode.cn/problems/minimum-window-substring/
// Level: Hard
// Date: 2025-04-16

class Solution {
    private:
        bool check(unordered_map<char, int>& t_cnt, unordered_map<char, int>& s_cnt) {
            for (auto it = t_cnt.begin(); it != t_cnt.end(); it++) {
                if (s_cnt[it->first] < it->second) {
                    return false;
                }
            }
            return true;
        }

    public:
        string minWindow(string s, string t) {
            if (s.size() < t.size()) {
                return "";
            }
            unordered_map<char, int> t_cnt;
            for (char c : t) {
                t_cnt[c]++;
            }
            int required = t_cnt.size();
            unordered_map<char, int> s_cnt;
            int left = 0, right = 0;
            int min_len = INT_MAX;
            int ans_left = 0;
            int formed = 0;
            while (right < s.size()) {
                char c = s[right];
                s_cnt[c]++;
                if (t_cnt.count(c) && s_cnt[c] == t_cnt[c]) {
                    formed++;
                }

                while (formed == required && left <= right) {
                    if (right - left + 1 < min_len) {
                        min_len = right - left + 1;
                        ans_left = left;
                    }

                    char left_c = s[left];
                    s_cnt[left_c]--;
                    if (t_cnt.count(left_c) && s_cnt[left_c] < t_cnt[left_c]) {
                        formed--;
                    }
                    left++;
                }
                right++;
            }

            return min_len == INT_MAX ? "" : s.substr(ans_left, min_len);
        }
};
