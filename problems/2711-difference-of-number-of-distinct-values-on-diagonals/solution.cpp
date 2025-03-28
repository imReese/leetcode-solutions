// Link: https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/
// Level: Medium
// Date: 2025-03-28

class Solution {
    public:
        vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> ans(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    unordered_set<int> topLeft;
                    unordered_set<int> bottomRight;
                    int x = i - 1;
                    int y = j - 1;
                    while (x >= 0 && y >= 0) {
                        topLeft.insert(grid[x][y]);
                        x--;
                        y--;
                    }
                    x = i + 1;
                    y = j + 1;
                    while (x < m && y < n) {
                        bottomRight.insert(grid[x][y]);
                        x++;
                        y++;
                    }
                    ans[i][j] = abs((int)topLeft.size() - (int)bottomRight.size());
                }
            }
            return ans;
        }
};