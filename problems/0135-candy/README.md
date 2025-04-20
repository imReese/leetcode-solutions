# 135. 分发糖果 (Candy)

[LeetCode 原题链接](https://leetcode.cn/problems/candy/) | 难度: **困难** | 标签: `贪心`、`数组`

## 题目描述

`n` 个孩子站成一排. 给你一个整数数组 `ratings` 表示每个孩子的评分.

你需要按照以下要求, 给这些孩子分发糖果:

- 每个孩子至少分配到 `1` 个糖果.
- 相邻两个孩子评分更高的孩子会获得更多的糖果.

请你给每个孩子分发糖果, 计算并返回需要准备的 **最少糖果数目**.

示例:

```plaintext
输入: ratings = [1,0,2]
输出: 5
解释: 你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果.
```

## 解法思路

### 贪心+两次遍历

- 核心思想: 通过两次独立的线性扫描, 分别处理左右邻居的约束条件, 最终合并结果
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> left(n);
            for (int i = 0; i < n; i++) {
                if (i > 0 && ratings[i] > ratings[i - 1]) {
                    left[i] = left[i - 1] + 1;
                } else {
                    left[i] = 1;
                }
            }
            vector<int> right(n);
            for (int i = n - 1; i >= 0; i--) {
                if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                    right[i] = right[i + 1] + 1;
                } else {
                    right[i] = 1;
                }
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += max(left[i], right[i]);
            }
            return res;
        }
};
```

## 相似题目

- [3122. 使矩阵满足条件的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-satisfy-conditions/)

## Tags

[贪心](/tags/greedy.md) | [数组](/tags/array.md)
