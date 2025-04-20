# 37. 解数独 (Sudoku Solver)

[LeetCode 原题链接](https://leetcode.cn/problems/sudoku-solver/) | 难度: **困难** | 标签: `数组`、`哈希表`、`回溯`、`矩阵`

## 题目描述

编写一个程序, 通过填充空格来解决数独问题.

数独的解法需**遵循如下规则**:

  1. 数字 `1-9` 在每一行只能出现一次.
  2. 数字 `1-9` 在每一列只能出现一次.
  3. 数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次. (请参考示例图)

数独部分空格内已填入了数字, 空白格用 `'.'` 表示.

示例:

![37. 解数独 - 示例](/problems/0037-sudoku-solver/ex-in.png)

```plaintext
输入: board = [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
输出: [
    ["5","3","4","6","7","8","9","1","2"],
    ["6","7","2","1","9","5","3","4","8"],
    ["1","9","8","3","4","2","5","6","7"],
    ["8","5","9","7","6","1","4","2","3"],
    ["4","2","6","8","5","3","7","9","1"],
    ["7","1","3","9","2","4","8","5","6"],
    ["9","6","1","5","3","7","2","8","4"],
    ["2","8","7","4","1","9","6","3","5"],
    ["3","4","5","2","8","6","1","7","9"]]
解释: 输入的数独如上图所示,唯一有效的解决方案如下所示:
```

![37. 解数独 - 示例](/problems/0037-sudoku-solver/ex-out.png)

## 解法思路

### 回溯

- 核心思想: 使用数组记录每个数字是否出现 对所有需要填空的位置记入spaces 然后对spaces中的每个位置选择1-9的数字进行填充
- 时间复杂度: O(9^n) n 为空格的数量, 9 为每个空格可以填入的数字个数.
- 空间复杂度：O(n) n 为数独的大小.

```cpp
class Solution {
    private:
        bool line[9][9];
        bool column[9][9];
        bool block[3][3][9];
        bool valid;
        vector<pair<int, int>> spaces;
    public:
        void dfs(vector<vector<char>>& board, int pos) {
            if (pos == spaces.size()) {
                valid = true;
                return;
            }
            auto [i, j] = spaces[pos];
            for (int digit = 0; digit < 9 && !valid; digit++) {
                if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
                    line[i][digit] = column[j][digit] = block[i/3][j/3][digit] = true;
                    board[i][j] = digit + '0' + 1;
                    dfs(board, pos + 1);
                    line[i][digit] = column[j][digit] = block[i/3][j/3][digit] = false;
                }
            }
        }
        void solveSudoku(vector<vector<char>>& board) {
            memset(line, false, sizeof(line));
            memset(column, false, sizeof(column));
            memset(block, false, sizeof(block));
            valid = false;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        spaces.emplace_back(i, j);
                    } else {
                        int digit = board[i][j] - '0' - 1;
                        line[i][digit] = column[j][digit] = block[i/3][j/3][digit] = true;
                    }
                }
            }
            dfs(board, 0);
        }
};
```

## 相似题目

- [36. 有效的数独](https://leetcode.cn/problems/valid-sudoku/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [回溯](/tags/backtracking.md) | [矩阵](/tags/matrix.md)
