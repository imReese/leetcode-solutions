# 368. 最大整除子集 (Largest Divisible Subset)

[LeetCode 原题链接](https://leetcode.cn/problems/largest-divisible-subset/) | 难度: **中等** | 标签: `数组`、`数学`、`动态规划`、`排序`

## 题目描述

给你一个由 无重复 正整数组成的集合 `nums`, 请你找出并返回其中最大的整除子集 `answer`, 子集中每一元素对 `(answer[i], answer[j])` 都应当满足:

- `answer[i] % answer[j] == 0`, 或
- `answer[j] % answer[i] == 0`

如果存在多个有效解子集，返回其中任何一个均可.

示例:

```plaintext
输入: nums = [1,2,3]
输出: [1,2]
解释: [1,3] 也会被视为正确答案.
```

## 解法思路

### 动态规划

- 核心思想: dp[i]表示前i个数组中, 以第i个数为结尾的最大整除子集.
  - 状态转移方程: dp[i] = max(dp[j] + 1), 其中 0 <= j < i, nums[i] % nums[j] == 0
- 边界条件: dp[0] = 1
- 时间复杂度: O(n²)
- 空间复杂度: O(n²)

```cpp
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int len = nums.size();
            vector<vector<int>> dp(len, vector<int>());
            sort(nums.begin(), nums.end());
            int maxLen = 1;
            dp[0] = vector<int>(1, nums[0]);
            vector<int> res = dp[0];
            for (int i = 1; i < len; i++) {
                dp[i].push_back(nums[i]);
                for (int j = i - 1; j >= 0; j--) {
                    if (nums[i] % nums[j] == 0) {
                        if (dp[j].size() + 1 > dp[i].size()) {
                            dp[i] = dp[j];
                            dp[i].push_back(nums[i]);
                        }
                    }
                }
                if (dp[i].size() > maxLen) {
                    maxLen = dp[i].size();
                    res = dp[i];
                }
            }
            return res;
        }
};
```

## Tags

[数组](/tags/array.md) | [数学](/tags/math.md) | [动态规划](/tags/dynamic-programming.md) | [排序](/tags/sorting.md)
