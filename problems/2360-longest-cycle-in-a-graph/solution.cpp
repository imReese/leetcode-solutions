// Link: https://leetcode.cn/problems/longest-cycle-in-a-graph/
// Level: Hard
// Date: 2025-03-29

class Solution {
    public:
        int longestCycle(vector<int>& edges) {
            int n = edges.size();
            vector<bool> visited(n, false);
            int max_len = -1;

            for (int i = 0; i < n; i++) {
                if (visited[i])
                    continue;

                unordered_map<int, int> pos;
                int cur = i;
                int step = 0;

                while (cur != -1 && !visited[cur]) {
                    if (pos.find(cur) != pos.end()) {
                        max_len = max(max_len, step - pos[cur]);
                        break;
                    }
                    pos[cur] = step++;
                    visited[cur] = true;
                    cur = edges[cur];
                }

                if (cur != -1 && pos.count(cur)) {
                    max_len = max(max_len, step - pos[cur]);
                }
            }
            return max_len > 0 ? max_len : -1;
        }
};