// Link: https://leetcode.cn/problems/finding-3-digit-even-numbers/
// Level: Easy
// Date: 2025-05-12

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        if (n < 3) {
            return {};
        }

        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j || digits[k] % 2 != 0) {
                        continue;
                    }
                    s.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        vector<int> res(s.begin(), s.end());
        sort(res.begin(), res.end());
        return res;
    }
};
