// Link: https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/
// Level: Easy
// Date: 2025-02-17

class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int len = arr.size();
            int target = arr[0], count = 1;
            for (int i = 1; i < len; ++i) {
                if (arr[i] == target) {
                    ++count;
                    if (count * 4 > len) {
                        return target;
                    }
                } else {
                    target = arr[i];
                    count = 1;
                }
            }
            return target;
        }
};