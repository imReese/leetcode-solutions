# 3250. 单调数组对的数目 I (Find the Count of Monotonic Pairs I)

[LeetCode 原题链接](https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-i/) | 难度: **困难** | 标签: `数组`、`数学`、`动态规划`、`组合数学`、`前缀和`

## 题目描述

给你一个长度为 `n` 的 正 整数数组 `nums`.

如果两个 非负 整数数组 `(arr1, arr2)` 满足以下条件, 我们称它们是 单调 数组对:

- 两个数组的长度都是 `n` .
- `arr1` 是单调 非递减 的, 换句话说 `arr1[0] <= arr1[1] <= ... <= arr1[n - 1]`.
- `arr2` 是单调 非递增 的, 换句话说 `arr2[0] >= arr2[1] >= ... >= arr2[n - 1]`.
- 对于所有的 `0 <= i <= n - 1` 都有 `arr1[i] + arr2[i] == nums[i]`.

请你返回所有 单调 数组对的数目.

由于答案可能很大, 请你将它对 `109 + 7` 取余 后返回.

示例:

```plaintext
输入: nums = [2,3,2]

输出: 4

解释:

单调数组对包括: 

  1. `([0, 1, 1], [2, 2, 1])`
  2. `([0, 1, 2], [2, 2, 0])`
  3. `([0, 2, 2], [2, 1, 0])`
  4. `([1, 2, 2], [1, 1, 0])`
```

## 解法思路

### 动态规划

- 核心思想:
  - 对于唯一的arr1有唯一确定的arr2
  - dp[i][j]表示当arr1[i] = j时 nums中前i+1个元素组成的单调数组的数目
  - 状态转移方程: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - d]
    - 其中 d = max(0, nums[i] - nums[i - 1])
- 时间复杂度: O(n * m)
- 空间复杂度: O(n * m)

其中 m 是数组中最大的元素.

```cpp
class Solution {
    public:
        int countOfPairs(vector<int>& nums) {
            int n = nums.size();
            int m = *max_element(nums.begin(), nums.end());
            int mod = 1e9 + 7;
            int res = 0;
            vector<vector<int>> dp(n, vector<int>(m + 1, 0));
            for (int j = 0; j <= nums[0]; j++) {
                dp[0][j] = 1;
            }
            for (int i = 1; i < n; i++) {
                int d = max(0, nums[i] - nums[i - 1]);
                for (int j = d; j <= nums[i]; j++) {
                    if (j == 0) {
                        dp[i][j] = dp[i - 1][j - d];
                    } else {
                        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - d]) % mod;
                    }
                }
            }
            for (int num: dp[n - 1]) {
                res = (res + num) % mod;
            }
            return res;
        }
};
```

## 相似题目

- [896. 单调数列](https://leetcode.cn/problems/monotonic-array/)

## Tags

[数组](/tags/array.md) | [数学](/tags/math.md) | [动态规划](/tags/dynamic-programming.md)
