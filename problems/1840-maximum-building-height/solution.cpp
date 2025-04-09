// Link: https://leetcode.cn/problems/maximum-building-height/
// Level: Hard
// Date: 2025-04-09

class Solution {
    public:
        int maxBuilding(int n, vector<vector<int>>& restrictions) {
            int res = 0;
            auto&& r = restrictions;
            r.push_back({1, 0});
            sort(r.begin(), r.end());
            if (r.back()[0] != n) {
                r.push_back({n, n - 1});
            }

            int m = r.size();
            for (int i = 1; i < m; i++) {
                r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
            }
            for (int j = m - 2; j >= 0; j--) {
                r[j][1] = min(r[j][1], r[j + 1][1] + (r[j + 1][0] - r[j][0]));
            }

            for (int i = 0; i < m - 1; i++) {
                int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
                res = max(res, best);
            }

            return res;
        }
};