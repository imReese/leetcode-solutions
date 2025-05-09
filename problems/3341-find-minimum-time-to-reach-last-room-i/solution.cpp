// Link: https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-i/
// Level: Medium
// Date: 2025-05-09

class Solution {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size(), m = moveTime[0].size();
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            dist[0][0] = 0;
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
            q.emplace(0, 0, 0);

            while (!q.empty()) {
                auto [t, x, y] = q.top();
                q.pop();
                if (x == n - 1 && y == m - 1) {
                    return t;
                }

                if (t > dist[x][y]) {
                    continue;
                }

                for (auto &d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        int nt = max(t, moveTime[nx][ny]) + 1;
                        if (nt < dist[nx][ny]) {
                            dist[nx][ny] = nt;
                            q.emplace(nt, nx, ny);
                        }
                    }
                }
            }
            return -1;
        }
};
