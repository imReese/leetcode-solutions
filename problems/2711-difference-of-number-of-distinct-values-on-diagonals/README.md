# 2711. 对角线上不同值的数量差 (Difference of Number of Distinct Values on Diagonals)

[LeetCode 原题链接](https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/) | 难度: **中等** | 标签: `数组`、`哈希表`、`矩阵`

## 题目描述

给你一个下标从 0 开始、大小为 m x n 的二维矩阵 grid, 请你求解大小同样为 m x n 的答案矩阵 answer.
矩阵 answer 中每个单元格 (r, c) 的值可以按下述方式进行计算:

- 令 topLeft[r][c] 为矩阵 grid 中单元格 (r, c) 左上角对角线上 不同值 的数量.
- 令 bottomRight[r][c] 为矩阵 grid 中单元格 (r, c) 右下角对角线上 不同值 的数量.

然后 answer[r][c] = |topLeft[r][c] - bottomRight[r][c]|.
返回矩阵 answer.

矩阵对角线 是从最顶行或最左列的某个单元格开始,向右下方向走到矩阵末尾的对角线.

如果单元格 (r1, c1) 和单元格 (r, c) 属于同一条对角线且 r1 < r , 则单元格 (r1, c1) 属于单元格 (r, c) 的左上对角线. 类似地, 可以定义右下对角线.

示例:

![2711. 对角线上不同值的数量差 - 示例](https://github.com/imReese/leetcode-solutions/blob/main/problems/2711-difference-of-number-of-distinct-values-on-diagonals/ex.png)

```plaintext
输入：grid = [[1, 2, 3], [3, 1, 5], [3, 2, 1]]
输出：[[1, 1, 0], [1, 0, 1], [0, 1, 1]]
解释：第 1 个图表示最初的矩阵 grid.
第 2 个图表示对单元格 (0, 0) 计算,其中蓝色单元格是位于右下对角线的单元格.
第 3 个图表示对单元格 (1, 2) 计算,其中红色单元格是位于左上对角线的单元格.
第 4 个图表示对单元格 (1, 1) 计算,其中蓝色单元格是位于右下对角线的单元格, 红色单元格是位于左上对角线的单元格.
- 单元格 (0, 0) 的右下对角线包含 [1,1] , 而左上对角线包含 []. 对应答案是 |1 - 0| = 1.
- 单元格 (1, 2) 的右下对角线包含 [] , 而左上对角线包含 [2]. 对应答案是 |0 - 1| = 1.
- 单元格 (1, 1) 的右下对角线包含 [1] , 而左上对角线包含 [1]. 对应答案是 |1 - 1| = 0.
其他单元格的对应答案也可以按照这样的流程进行计算.
```

## 解法思路

### 哈希表 + 遍历

- 核心思想: 用哈希表分别统计，左上角和右下角对角线上不同值的数量
- 时间复杂度: O(m x n x min(m, n))
- 空间复杂度: O(min(m, n))

```cpp
class Solution {
    public:
        vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> ans(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    unordered_set<int> topLeft;
                    unordered_set<int> bottomRight;
                    int x = i - 1;
                    int y = j - 1;
                    while (x >= 0 && y >= 0) {
                        topLeft.insert(grid[x][y]);
                        x--;
                        y--;
                    }
                    x = i + 1;
                    y = j + 1;
                    while (x < m && y < n) {
                        bottomRight.insert(grid[x][y]);
                        x++;
                        y++;
                    }
                    ans[i][j] = abs((int)topLeft.size() - (int)bottomRight.size());
                }
            }
            return ans;
        }
};
```

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [矩阵](/tags/matrix.md)
