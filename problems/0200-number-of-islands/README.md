# 200. 岛屿数量 (Number of Islands)

[LeetCode 原题链接](https://leetcode.cn/problems/number-of-islands/) | 难度: **中等** | 标签: `深度优先搜索`、`广度优先搜索`、`并查集`、`数组`、`矩阵`

## 题目描述

给你一个由 `'1'`（陆地）和 `'0'`（水）组成的的二维网格, 请你计算网格中岛屿的数量.

岛屿总是被水包围, 并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成.

此外, 你可以假设该网格的四条边均被水包围.

示例:

```plaintext
输入: grid = [
      ["1","1","1","1","0"],
      ["1","1","0","1","0"],
      ["1","1","0","0","0"],
      ["0","0","0","0","0"]
    ]
输出: 1
```

## 解法思路

### 方法一：深度优先搜索

- 时间复杂度: O(mn)
- 空间复杂度: O(mn)

```cpp
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size(), cols = grid[0].size();
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == '0') {
            return;
        }      
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int cnt = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
```

### 方法二：广度优先搜索

- 时间复杂度: O(mn)
- 空间复杂度: O(min(m,n))

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        rows, cols = len(grid), len(grid[0])

        cnt = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    cnt += 1
                    queue = deque([(i, j)])
                    grid[i][j] = "0"
                    while queue:
                        x, y = queue.popleft()
                        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == "1":
                                grid[nx][ny] = "0"
                                queue.append((nx, ny))
        return cnt
```

## 相似题目

- [130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions/)

## Tags

[深度优先搜索](/tags/depth-first-search.md) | [广度优先搜索](/tags/breadth-first-search.md) | [并查集](/tags/union-find.md) | [数组](/tags/array.md) | [矩阵](/tags/matrix.md)
