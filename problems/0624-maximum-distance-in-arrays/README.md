# 624. 数组列表中的最大距离 (Maximum Distance in Arrays)

[LeetCode 原题链接](https://leetcode.cn/problems/maximum-distance-in-arrays/) | 难度: **中等** | 标签: `贪心`、`数组`

## 题目描述

给定 `m` 个数组，每个数组都已经按照升序排好序了。

现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数 `a` 和 `b` 之间的距离定义为它们差的绝对值 `|a-b|` 。

返回最大距离。

**示例 1：**
[code] 
    **输入：**[[1,2,3],[4,5],[1,2,3]]
    **输出：** 4
    **解释：**
    一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
    
[/code]

**示例 2：**
[code] 
    **输入：** arrays = [[1],[1]]
    **输出：** 0
    
[/code]

 

**提示：**

  * `m == arrays.length`
  * `2 <= m <= 105`
  * `1 <= arrays[i].length <= 500`
  * `-104 <= arrays[i][j] <= 104`
  * `arrays[i]` 以 **升序**  排序。
  * 所有数组中最多有 `105` 个整数。

## 解法思路

```cpp
class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            int ans = 0;
            int minVal = arrays[0][0];
            int maxVal = arrays[0].back();
            for (int i = 1; i < arrays.size(); ++i) {
                ans = max(ans, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i][0]))); 
                minVal = min(minVal, arrays[i][0]);
                maxVal = max(maxVal, arrays[i].back());
            }
            return ans;
        }
};
```
