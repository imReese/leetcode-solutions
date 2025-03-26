// Link: https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-ii/
// Level: Medium
// Date: 2025-02-20

class Solution {
    public:
        int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
            int n = startTime.size();
            vector<int> interval;
            interval.push_back(startTime[0] - 0);
            for (int i = 1; i < n; i++) {
                interval.push_back(startTime[i] - endTime[i - 1]);
            }
            interval.push_back(eventTime - endTime.back());

            vector<int> meetingTime;
            for (int i = 0; i < n; i++) {
                meetingTime.push_back(endTime[i] - startTime[i]);
            }

            vector<int> lRoom(n); // lRoom[i] 表示第i个会议左侧最大的空余时长 不含相邻空余时长
            vector<int> rRoom(n); // rRoom[i] 表示第i个会议右侧最大的空余时长 不含相邻空余时长
            lRoom[0] = 0;
            for (int i = 1; i < n; i++) {
                lRoom[i] = max(lRoom[i - 1], interval[i - 1]);
            }
            rRoom[n - 1] = 0;
            for (int i = n - 2; i >= 0; i--) {
                rRoom[i] = max(rRoom[i + 1], interval[i + 2]);
            }

            int ans = 0;
            int tmp = 0;
            // interval[i] meetingTime[j] interval[i + 1] i == j
            for (int i = 0, j = 0; i < interval.size(), j < meetingTime.size(); i++, j++) {
                int isMovable = false;
                if (meetingTime[j] <= max(lRoom[j], rRoom[j])) {
                    isMovable = true;
                }
                if (isMovable) {
                    tmp = interval[i] + interval[i + 1] + meetingTime[j];
                } else {
                    tmp = interval[i] + interval[i + 1];
                }
                ans = max(ans, tmp);
            }
            return ans;
        }
};

class Solution {
    public:
        int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
            vector<int> interval;
            interval.push_back(startTime[0] - 0);
            for (int i = 1; i < startTime.size(); i++) {
                interval.push_back(startTime[i] - endTime[i - 1]);
            }
            interval.push_back(eventTime - endTime.back());

            vector<int> meetingTime;
            for (int i = 0; i < startTime.size(); i++) {
                meetingTime.push_back(endTime[i] - startTime[i]);
            }

            int ans = 0;
            int tmp = 0;
            // interval[i] meetingTime[j] interval[i + 1] i == j
            for (int i = 0, j = 0; i < interval.size(), j < meetingTime.size(); i++, j++) {
                int isMovable = false;
                vector<int> remainInterval = interval;
                remainInterval.erase(remainInterval.begin() + i);
                remainInterval.erase(remainInterval.begin() + i);
                if (meetingTime[i] <= *max_element(remainInterval.begin(), remainInterval.end())) {
                    isMovable = true;
                }
                if (isMovable) {
                    tmp = interval[i] + interval[i + 1] + meetingTime[j];
                } else {
                    tmp = interval[i] + interval[i + 1];
                }
                ans = max(ans, tmp);
            }
            return ans;
        }
};