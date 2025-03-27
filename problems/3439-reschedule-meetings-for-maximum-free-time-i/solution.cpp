// Link: https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/
// Level: Medium
// Date: 2025-02-20

class Solution {
    public:
        int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
            vector<int> interval;
            interval.push_back(startTime[0] - 0);
            for (int i = 1; i < startTime.size(); i++) {
                interval.push_back(startTime[i] - endTime[i - 1]);
            }
            interval.push_back(eventTime - endTime.back());

            int ans = 0;
            int tmp = 0;
            k += 1;
            for (int i = 0; i < interval.size(); ++i) {
                tmp += interval[i];
                if (i >= k) {
                    tmp -= interval[i - k];
                }
                ans = max(ans, tmp);
            }
            return ans;
        }
};