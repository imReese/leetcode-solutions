# 416. 分割等和子集 (Partition Equal Subset Sum)

[LeetCode 原题链接](https://leetcode.cn/problems/partition-equal-subset-sum/) | 难度: **中等** | 标签: `数组`、`动态规划`

## 题目描述

给你一个 **只包含正整数** 的 **非空** 数组 `nums`. 请你判断是否可以将这个数组分割成两个子集, 使得两个子集的元素和相等.

示例:

```plaintext
输入: nums = [1,5,11,5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11]. 
```

## 解法思路

### 动态规划

- 核心思想: 依次选取nums中0到n-1个数 dp[j] 表示数组中是否存在和为 j 的子数组
- 时间复杂度: O(n * target) n为数组nums的长度 target为数组nums的元素和的一半
- 空间复杂度: O(target)

```cpp
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            if (n < 2) {
                return false;
            }
            int sum = 0, maxNum = 0;
            for (auto& num : nums) {
                sum += num;
                maxNum = max(num, maxNum);
            }
            if (sum & 1) {
                return false;
            }
            int target = sum / 2;
            if (maxNum > target) {
                return false;
            }
            vector<int> dp(target + 1, 0);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                int num = nums[i];
                for (int j = target; j >= num; j--) {
                    dp[j] |= dp[j - num];
                }
            }
            return dp[target];
        }
};
```

## 相似题目

- [698. 划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)

## Tags

[数组](/tags/array.md) | [动态规划](/tags/dynamic-programming.md)
