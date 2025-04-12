# 84. 柱状图中最大的矩形 (Largest Rectangle in Histogram)

[LeetCode 原题链接](https://leetcode.cn/problems/largest-rectangle-in-histogram) | 难度: **困难** | 标签: `栈`、`数组`、`单调栈`

## 题目描述

给定 _n_ 个非负整数, 用来表示柱状图中各个柱子的高度. 每个柱子彼此相邻, 且宽度为 1.

求在该柱状图中, 能够勾勒出来的矩形的最大面积.

示例:

![84. 柱状图中最大的矩形 - 示例](https://github.com/imReese/leetcode-solutions/blob/main/problems/0084-largest-rectangle-in-histogram/ex.png)

```plaintext
输入: heights = [2,1,5,6,2,3]
输出: 10
解释: 最大的矩形为图中红色区域, 面积为 10
```

## 解法思路

### 单调栈

- 核心思想: 使用单调栈来记录每个柱子的左右边界, 然后计算每个柱子的面积, 取最大值.
  - 单调栈: 单调栈中存储的是柱子的索引, 这些柱子的高度是单调递增的.
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> left(n), right(n);
            stack<int> mono_stack;
            for (int i = 0; i < n; i++) {
                while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                    mono_stack.pop();
                }
                left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
                mono_stack.push(i);
            }
            mono_stack = stack<int>();
            for (int i = n - 1; i >= 0; i--) {
                while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                    mono_stack.pop();
                }
                right[i] = (mono_stack.empty() ? n : mono_stack.top());
                mono_stack.push(i);
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
            }
            return ans;
        }
};
```

## 相似题目

- [85. 最大矩形](https://leetcode.cn/problems/maximal-rectangle/)

## Tags

[栈](/tags/stack.md) | [数组](/tags/array.md) | [单调栈](/tags/monotonic-stack.md)
