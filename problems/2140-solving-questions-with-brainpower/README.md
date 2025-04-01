# 2140. 解决智力问题 (Solving Questions With Brainpower)

[LeetCode 原题链接](https://leetcode.cn/problems/solving-questions-with-brainpower/) | 难度: **中等** | 标签: `数组`、`动态规划`

## 题目描述

给你一个下标从 0 开始的二维整数数组 questions , 其中 questions[i] = [pointsi, brainpoweri] .

这个数组表示一场考试里的一系列题目, 你需要 按顺序 （也就是从问题 0 开始依次解决）, 针对每个问题选择 解决 或者 跳过 操作. 解决问题 i 将让你 获得  pointsi 的分数, 但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri 个问题）. 如果你跳过问题 i , 你可以对下一个问题决定使用哪种操作.

- 比方说, 给你 questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
  - 如果问题 0 被解决了,  那么你可以获得 3 分, 但你不能解决问题 1 和 2 .
  - 如果你跳过问题 0 , 且解决问题 1 , 你将获得 4 分但是不能解决问题 2 和 3 .
请你返回这场考试里你能获得的 最高 分数.

## 解法思路

### 动态规划

- 核心思想: 从后往前遍历, 后一题做与否是不影响前一题的, 而前一天做与否影响后一题
  - 状态定义: dp[i] 表示从第 i 题开始做, 能获得的最高分数
  - 状态转移: dp[i] = max(points[i] + dp[i + skip + 1], dp[i + 1])
  - 边界条件: dp[n] = 0
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n + 1, 0);
            dp[n] = 0;
            for (int i = n - 1; i >= 0; i--) {
                long long points = questions[i][0];
                int skip = questions[i][1];
                int next = i + skip + 1 >= n ? n: i + skip + 1;
                dp[i] = max(points + dp[next], dp[i + 1]);
            }
            return dp[0];
        }
};
```

## 相似题目

[198. 打家劫舍 - 力扣](https://leetcode.cn/problems/house-robber/)

## Tags

[数组](/tags/array.md) | [动态规划](/tags/dynamic-programming.md)
