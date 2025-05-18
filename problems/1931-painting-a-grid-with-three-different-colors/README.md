# 1931. 用三种不同颜色为网格涂色 (Painting a Grid With Three Different Colors)

[LeetCode 原题链接](https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/) | 难度: **困难** | 标签: `动态规划`

## 题目描述

给你两个整数 `m` 和 `n`. 构造一个 `m x n` 的网格, 其中每个单元格最开始是白色. 请你用 **红、绿、蓝** 三种颜色为每个单元格涂色. 所有单元格都需要被涂色.

涂色方案需要满足: **不存在相邻两个单元格颜色相同的情况**. 返回网格涂色的方法数. 因为答案可能非常大, 返回 **对**`109 + 7`**取余** 的结果.

示例:

![1931. 用三种不同颜色为网格涂色 - 示例](/problems/1931-painting-a-grid-with-three-different-colors/ex.png)

```plaintext
输入: m = 1, n = 1
输出: 3
解释: 如上图所示, 存在三种可能的涂色方案.
```

## 解法思路

### 动态规划+滚动数组

- 核心思想: 将每一列的颜色组合视为一个状态, 首先要筛选出所有满足相邻行颜色不同的列状态, 然后通过状态转移来计算每一列的涂色方案数.
  - 状态定义: `dp[i][j]` 表示第 `i` 列涂色方案数, `j` 表示第 `i` 列的状态. 由于每一列的状态只与前一列的状态有关, 所以可以使用滚动数组来优化空间复杂度.
  - 状态转移: 对于每一列的状态 `s2`, 遍历前一列的所有状态 `s1`, 如果 `s1` 和 `s2` 的颜色组合不相同, 则可以将 `s1` 转移到 `s2`, 即 `dp[i][j] += dp[i-1][j]`.
- 时间复杂度: O(3^2m)
- 空间复杂度: O(3^m)

```cpp
const int MOD = 1e9 + 7;

class Solution {
private:
    bool isValidColumn(int s, int m) {
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            int color = s % 3;
            if (color == prev) return false;
            prev = color;
            s /= 3;
        }
        return true;
    }

    bool canTransfer(int s1, int s2, int m) {
        for (int i = 0; i < m; ++i) {
            if (s1 % 3 == s2 % 3) return false;
            s1 /= 3;
            s2 /= 3;
        }
        return true;
    }

public:
    int colorTheGrid(int m, int n) {
        vector<int> valid_states;
        for (int s = 0; s < pow(3, m); s++) {
            if (isValidColumn(s, m)) {
                valid_states.emplace_back(s);
            }
        }
        int k = valid_states.size();
        if (k == 0) {
            return 0;
        }
        unordered_map<int, vector<int>> transitions;
        unordered_map<int, int> state_to_index;
        for (int i = 0; i < k; i++) {
            state_to_index[valid_states[i]] = i;
        }
        for (int s1 : valid_states) {
            for (int s2 : valid_states) {
                if (canTransfer(s1, s2, m)) {
                    transitions[s1].emplace_back(s2);
                }
            }
        }

        vector<long long> dp_prev(k, 1);
        for (int col = 1; col < n; col++) {
            vector<long long> dp_curr(k, 0);
            for (int i = 0; i < k; i++) {
                int s1 = valid_states[i];
                for (int s2 : transitions[s1]) {
                    int j = state_to_index[s2];
                    dp_curr[j] = (dp_curr[j] + dp_prev[i]) % MOD;
                }
            }
            dp_prev = dp_curr;
        }

        long long res = 0;
        for (int i = 0; i < k; i++) {
            res = (res + dp_prev[i]) % MOD;
        }
        return res;
    }
};
```

## 相似题目

- [1411. 给 N x 3 网格图涂色的方案数](https://leetcode.cn/problems/number-of-ways-to-paint-n-3-grid/)

## Tags

[动态规划](/tags/dynamic-programming.md)
