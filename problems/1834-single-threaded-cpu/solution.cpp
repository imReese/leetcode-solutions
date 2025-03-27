// Link: https://leetcode-cn.com/problems/single-threaded-cpu/
// Level: Medium
// Date: 2025-02-18

class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            int n = tasks.size();
            vector<int> ans;
            // 添加索引到任务中
            for (int i = 0; i < n; ++i) {
                tasks[i].push_back(i);
            }
            // 按开始时间排序
            sort(tasks.begin(), tasks.end());

            // 优先队列，按处理时间和索引排序
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

            long long curTime = 0;
            int taskIndex = 0;

            while (taskIndex < n || !pq.empty()) {
                if (pq.empty() && curTime < tasks[taskIndex][0]) {
                    curTime = tasks[taskIndex][0];
                }

                // 将可执行的任务加入优先队列
                while (taskIndex < n && tasks[taskIndex][0] <= curTime) {
                    pq.push({tasks[taskIndex][1], tasks[taskIndex][2]});
                    taskIndex++;
                }

                // 执行处理时间最短的任务
                auto [processTime, index] = pq.top();
                pq.pop();
                curTime += processTime;
                ans.push_back(index);
            }

            return ans;
        }
};
