# 2209. 用地毯覆盖后的最少白色砖块 (Minimum White Tiles After Covering With Carpets)

[LeetCode 原题链接](https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/) | 难度: **困难** | 标签: `字符串`、`动态规划`、`前缀和`

## 题目描述

给你一个下标从**  0** 开始的 **二进制**  字符串 `floor` ，它表示地板上砖块的颜色。

  * `floor[i] = '0'` 表示地板上第 `i` 块砖块的颜色是 **黑色**  。
  * `floor[i] = '1'` 表示地板上第 `i` 块砖块的颜色是 **白色**  。

同时给你 `numCarpets` 和 `carpetLen` 。你有 `numCarpets` 条 **黑色**  的地毯，每一条 **黑色**  的地毯长度都为 `carpetLen` 块砖块。请你使用这些地毯去覆盖砖块，使得未被覆盖的剩余 **白色**  砖块的数目 **最小**  。地毯相互之间可以覆盖。

请你返回没被覆盖的白色砖块的 **最少**  数目。

 

**示例 1：**

![](https://assets.leetcode.com/uploads/2022/02/10/ex1-1.png)
[code] 
    **输入：** floor = "10110101", numCarpets = 2, carpetLen = 2
    **输出：** 2
    **解释：**
    上图展示了剩余 2 块白色砖块的方案。
    没有其他方案可以使未被覆盖的白色砖块少于 2 块。
    
[/code]

**示例 2：**

![](https://assets.leetcode.com/uploads/2022/02/10/ex2.png)
[code] 
    **输入：** floor = "11111", numCarpets = 2, carpetLen = 3
    **输出：** 0
    **解释：**
    上图展示了所有白色砖块都被覆盖的一种方案。
    注意，地毯相互之间可以覆盖。
    
[/code]

 

**提示：**

  * `1 <= carpetLen <= floor.length <= 1000`
  * `floor[i]` 要么是 `'0'` ，要么是 `'1'` 。
  * `1 <= numCarpets <= 1000`

## 解法思路

```cpp
class Solution {
    public:
        static constexpr int INF = 0x3f3f3f3f;
        int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
            int n = floor.size();
            vector<vector<int>> d(n + 1, vector<int>(numCarpets + 1, INF));
            for (int j = 0; j <= numCarpets; ++j) {
                d[0][j] = 0;
            }
            for (int i = 1; i <= n; ++i) {
               d[i][0] = d[i - 1][0] + (floor[i - 1] == '1'); 
            }
            for (int i = 1; i <= n; ++i) {
               for (int j = 1; j <= numCarpets; ++j) {
                    d[i][j] = d[i - 1][j] + (floor[i - 1] == '1');
                    d[i][j] = min(d[i][j], d[max(0, i - carpetLen)][j - 1]);
               }
            }
            return d[n][numCarpets];
        }
};
class Solution {
    public:
        int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        }
};
```
