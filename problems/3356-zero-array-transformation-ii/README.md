# 3356. 零数组变换 II (Zero Array Transformation II)

[LeetCode 原题链接](https://leetcode.cn/problems/zero-array-transformation-ii/) | 难度: **中等** | 标签: `数组`、`二分查找`、`前缀和`

## 题目描述

给你一个长度为 `n` 的整数数组 `nums` 和一个二维数组 `queries`, 其中 `queries[i] = [li, ri, vali]`.

每个 `queries[i]` 表示在 `nums` 上执行以下操作:

- 将 `nums` 中 `[li, ri]` 范围内的每个下标对应元素的值 **最多** 减少 `vali`.
- 每个下标的减少的数值可以 **独立** 选择.

**零数组** 是指所有元素都等于 0 的数组.

返回 `k` 可以取到的 **最小** **非负** 值, 使得在 **顺序** 处理前 `k` 个查询后, `nums` 变成 **零数组**. 如果不存在这样的 `k`, 则返回 -1.

示例:

```plaintext
输入: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
输出: 2
解释:
  对于 i = 0(l = 0, r = 2, val = 1):
  - 在下标 `[0, 1, 2]` 处分别减少 `[1, 0, 1]`.
  - 数组将变为 `[1, 0, 1]`.
  对于 i = 1(l = 0, r = 2, val = 1):
  - 在下标 `[0, 1, 2]` 处分别减少 `[1, 0, 1]`.
  - 数组将变为 `[0, 0, 0]`，这是一个零数组。因此，`k` 的最小值为 2.
```

## 解法思路

### 二分查找 + 前缀和

- 核心思想: 二分查找 `k` 的值, 判断前 `k` 个查询是否能使 `nums` 变成零数组.
- 时间复杂度: O(nlogm) n为 nums 的长度, m 为 queries 的长度
- 空间复杂度: O(n)

```cpp
class Solution {
private:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> pre(n + 2, 0);
        for (int i = 0; i < k; ++i) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            pre[l] -= val;
            if (r + 1 < n) {
                pre[r + 1] += val;
            }
        }
        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum += pre[i];
            if (nums[i] + prefixSum > 0) {
                return false;
            }
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int left = -1, right = m + 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (check(nums, queries, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right <= m ? right : -1;
    }
};
```

## 相似题目

- [1109. 航班预订统计](https://leetcode.cn/problems/corporate-flight-bookings/)

## Tags

[数组](/tags/array.md) | [二分查找](/tags/binary-search.md) | [前缀和](/tags/prefix-sum.md)
