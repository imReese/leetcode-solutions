// Link: https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/
// Level: Medium
// Date: 2025-02-18

class Solution {
    public:
        vector<int> statisticalResult(vector<int>& arrayA) {
            int n = arrayA.size();
            vector<int> arrayB(n, 1);

            int zeroCount = 0;
            int nonZeroMul = 1;
            for (int num : arrayA) {
                if (num == 0) {
                    zeroCount++;
                } else {
                    nonZeroMul *= num;
                }
            }

            if (zeroCount == 0) {
                for (int i = 0; i < n; i++) {
                    arrayB[i] = nonZeroMul / arrayA[i];
                }
            } else if (zeroCount == 1) {
                for (int i = 0; i < n; i++) {
                    if (arrayA[i] == 0) {
                        arrayB[i] = nonZeroMul;
                    } else {
                        arrayB[i] = 0;
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    arrayB[i] = 0;
                }
            }
            return arrayB;
        }
};