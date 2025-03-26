// Link: https://leetcode.cn/problems/where-will-the-ball-fall/
// Level: Medium
// Date: 2025-02-15

class Solution {
    public:
        vector<int> findBall(vector<vector<int>>& grid) {
            int n = grid[0].size();
            vector<int> answer(n, -1);
            for (int j = 0; j < n; ++j) {
                int col = j;
                for (auto &row : grid) {
                    int dir = row[col];
                    col += dir;
                    if (col < 0 || col >= n || row[col] != dir) {
                        col = -1;
                        break;
                    }
                }
                answer[j] = col;
            }
            return answer;
        }
  
};