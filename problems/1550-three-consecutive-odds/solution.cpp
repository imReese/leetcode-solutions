// Link: https://leetcode.cn/problems/three-consecutive-odds/
// Level: Easy
// Date: 2025-05-11

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= n - 3; i++) {
            if ((arr[i] & 1) && (arr[i+1] & 1) && (arr[i+2] & 1)) {
                return true;
            }
        }
        return false;
    }
};
