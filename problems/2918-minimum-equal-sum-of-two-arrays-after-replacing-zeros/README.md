# 2918. 数组的最小相等和 (Minimum Equal Sum of Two Arrays After Replacing Zeros)

[LeetCode 原题链接](https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/) | 难度: **中等** | 标签: `贪心`、`数组`

## 题目描述

给你两个由正整数和 `0` 组成的数组 `nums1` 和 `nums2`.

你必须将两个数组中的**所有** `0` 替换为 **严格** 正整数, 并且满足两个数组中所有元素的和 **相等**.

返回 **最小** 相等和, 如果无法使两数组相等, 则返回 _`-1`_.

示例:

```plaintext
输入: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
输出: 12
解释: 可以按下述方式替换数组中的 0:
  - 用 2 和 4 替换 nums1 中的两个 0. 得到 nums1 = [3,2,2,1,4].
  - 用 1 替换 nums2 中的一个 0. 得到 nums2 = [6,5,1].
两个数组的元素和相等, 都等于 12. 可以证明这是可以获得的最小相等和.
```

## 解法思路

### 数学

- 核心思想: 分别计算两个数组的和及零的个数, 每个数组的最小可能和为非零和+零的个数
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, zero1 = 0;
        for (int num : nums1) {
            if (num == 0) {
                zero1++;
            }
            sum1 += num;
        }
        long long sum2 = 0, zero2 = 0;
        for (int num : nums2) {
            if (num == 0) {
                zero2++;
            }
            sum2 += num;
        }
        long long s1 = sum1 + zero1;
        long long s2 = sum2 + zero2;
        if (zero1 == 0 && zero2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        } else if (zero1 == 0) {
            return (sum1 >= s2) ? sum1 : -1;
        } else if (zero2 == 0) {
            return (sum2 >= s1) ? sum2 : -1;
        } else {
            return max(s1, s2);
        }
    }
};
```

## Tags

[贪心](/tags/greedy.md) | [数组](/tags/array.md)
