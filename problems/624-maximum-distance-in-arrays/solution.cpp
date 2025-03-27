// Link: https://leetcode.cn/problems/maximum-distance-in-arrays/
// Level: Medium
// Date: 2025-02-19

class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            int ans = 0;
            int minVal = arrays[0][0];
            int maxVal = arrays[0].back();
            for (int i = 1; i < arrays.size(); ++i) {
                // minVal 之前数组的最小值
                // maxVal 之前数组的最大值
                ans = max(ans, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i][0]))); 
                minVal = min(minVal, arrays[i][0]);
                maxVal = max(maxVal, arrays[i].back());
            }
            return ans;
        }
};