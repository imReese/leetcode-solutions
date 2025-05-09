// Link: https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-ii/
// Level: Medium
// Date: 2025-05-09

class Solution {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size(), m = moveTime[0].size();
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            dist[0][0] = 0;
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
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
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    int cost = 1 + ((x ^ y) & 1);
                    int nt = max(t, moveTime[nx][ny]) + cost;
                    if (nt < dist[nx][ny]) {
                        dist[nx][ny] = nt;
                        q.emplace(nt, nx, ny);
                    }
                }
            }
            return -1;
        }
};
