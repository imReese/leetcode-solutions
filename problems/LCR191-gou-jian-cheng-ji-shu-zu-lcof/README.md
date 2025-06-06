# LCR 191. 按规则计算统计结果 (按规则计算统计结果)

[LeetCode 原题链接](https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/) | 难度: **中等** | 标签: `数组`、`前缀和`

## 题目描述

为了深入了解这些生物群体的生态特征，你们进行了大量的实地观察和数据采集。数组 `arrayA` 记录了各个生物群体数量数据，其中 `arrayA[i]` 表示第 `i` 个生物群体的数量。请返回一个数组 `arrayB`，该数组为基于数组 `arrayA` 中的数据计算得出的结果，其中 `arrayB[i]` 表示将第 `i` 个生物群体的数量从总体中排除后的其他数量的乘积。

 

**示例 1：**
[code] 
    **输入：** arrayA = [2, 4, 6, 8, 10]
    **输出：**[1920, 960, 640, 480, 384]
    
[/code]

 

**提示：**

  * 所有元素乘积之和不会溢出 32 位整数
  * `arrayA.length <= 100000`

## 解法思路

```cpp
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
```
