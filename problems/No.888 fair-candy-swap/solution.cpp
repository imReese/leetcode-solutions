// Link: https://leetcode.cn/problems/fair-candy-swap/
// Level: Easy
// Date: 2025-02-22

class Solution {
    public:
        vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
            int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
            int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
            int delta = (aliceSum - bobSum) / 2;
            unordered_set<int> aliceSet(aliceSizes.begin(), aliceSizes.end());
            unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
            vector<int> res;
            for (int x : aliceSet) {
                if (bobSet.count(x - delta)) {
                    res = {x, x - delta};
                    break;
                }
            }
            return res;
        }
};