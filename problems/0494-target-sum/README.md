# 494. 目标和 (Target Sum)

[LeetCode 原题链接](https://leetcode.cn/problems/target-sum/) | 难度: **中等** | 标签: `数组`、`动态规划`、`回溯`

## 题目描述

给你一个非负整数数组 `nums` 和一个整数 `target`.

向数组中的每个整数前添加 `'+'` 或 `'-'`, 然后串联起所有整数, 可以构造一个 **表达式**:

- 例如, `nums = [2, 1]`, 可以在 `2` 之前添加 `'+'`, 在 `1` 之前添加 `'-'`, 然后串联起来得到表达式 `"+2-1"`.

返回可以通过上述方法构造的、运算结果等于 `target` 的不同 **表达式** 的数目.

示例:

```plaintext
输入: nums = [1,1,1,1,1], target = 3
输出: 5
解释: 一共有 5 种方法让最终目标和为 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3
```

## 解法思路

### 回溯

- 核心思想: 通过回溯遍历所有可能的表达式组合, 计算出符合条件的表达式数量.
- 时间复杂度: O(2^n)
- 空间复杂度: O(n)

```cpp
class Solution {
private:
    int backtrack(vector<int>& nums, int target, int idx, int curr_sum) {
        int n = nums.size();
        if (idx == n) {
            return curr_sum == target ? 1 : 0;
        }
        return backtrack(nums, target, idx + 1, curr_sum + nums[idx]) +
            backtrack(nums, target, idx + 1, curr_sum - nums[idx]);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = backtrack(nums, target, 0, 0);
        return res;
    }
};
```

## 相似题目

- [282. 给表达式添加运算符](https://leetcode.cn/problems/expression-add-operators/)

## Tags

[数组](/tags/array.md) | [动态规划](/tags/dynamic-programming.md) | [回溯](/tags/backtracking.md)
