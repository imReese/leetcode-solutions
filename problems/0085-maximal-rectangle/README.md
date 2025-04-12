# 85. 最大矩形 (Maximal Rectangle)

[LeetCode 原题链接](https://leetcode.cn/problems/maximal-rectangle/) | 难度: **困难** | 标签: `栈`、`数组`、`动态规划`、`矩阵`、`单调栈`

## 题目描述

给定一个仅包含 `0` 和 `1` 、大小为 `rows x cols` 的二维二进制矩阵, 找出只包含 `1` 的最大矩形, 并返回其面积.

示例:

[](![85. 最大矩形 - 示例](https://github.com/imReese/leetcode-solutions/blob/main/problems/0085-maximal-rectangle/ex.png))

```plaintext
输入: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出: 6
解释: 最大矩形如上图所示.
```

## 解法思路

### 单调栈

- 核心思想:
  - 首先通过二维数组left记录矩阵中每个元素左边连续1的数量, 这样每列从右往左看就是一个柱状图
  - 其次可以把每列看成一个柱状图, 每个柱状图的高度就是该列中连续1的数量, 使用单调栈来计算每个柱状图的最大矩形面积
- 时间复杂度: O(mn)
- 空间复杂度: O(mn)

```cpp
class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int m = matrix.size();
            if (m == 0) {
                return 0;
            }
            int n = matrix[0].size();
            vector<vector<int>> left(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == '1') {
                        left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                    }
                }
            }
            int res = 0;
            for (int j = 0; j < n; j++) {
                vector<int> up(m, 0), down(m, 0);
                stack<int> stk;
                for (int i = 0; i < m; i++) {
                    while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                        stk.pop();
                    }
                    up[i] = stk.empty() ? -1 : stk.top();
                    stk.push(i);
                }
                stk = stack<int>();
                for (int i = m - 1; i >= 0; i--) {
                    while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                        stk.pop();
                    }
                    down[i] = stk.empty() ? m : stk.top();
                    stk.push(i);
                }
                for (int i = 0; i < m; i++) {
                    int height = down[i] - up[i] - 1;
                    int area = height * left[i][j];
                    res = max(res, area);
                }
            }
            return res;
        }
};
```

## 相似题目

- [221. 最大正方形](https://leetcode.cn/problems/maximal-square/)

## Tags

[栈](/tags/stack.md) | [数组](/tags/array.md) | [动态规划](/tags/dynamic-programming.md) | [矩阵](/tags/matrix.md) | [单调栈](/tags/monotonic-stack.md)
