# 2239. 找到最接近 0 的数字 (Find Closest Number to Zero)

[LeetCode 原题链接](https://leetcode.cn/problems/find-closest-number-to-zero/) | 难度: **简单** | 标签: `数组`

## 题目描述

给你一个长度为 `n` 的整数数组 `nums`, 请你返回 `nums` 中最 接近 `0` 的数字. 如果有多个答案, 请你返回它们中的 最大值.

示例:

```plaintext
输入: nums = [-4,-2,1,4,8]
输出: 1
解释:
    -4 到 0 的距离为 |-4| = 4.
    -2 到 0 的距离为 |-2| = 2.
    1 到 0 的距离为 |1| = 1.
    4 到 0 的距离为 |4| = 4.
    8 到 0 的距离为 |8| = 8.
    所以, 数组中距离 0 最近的数字为 1.
```

## 解法思路

### 遍历

- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int findClosestNumber(vector<int>& nums) {
            int res = INT_MAX;
            for (int num : nums) {
                if (abs(num) < abs(res) || (abs(num) == abs(res) && num > res)) {
                    res = num;
                }
            }
            return res;
        }
};
```

## 相似题目

- [658. 找到 K 个最接近的元素](https://leetcode.cn/problems/find-k-closest-elements/)

## Tags

[数组](/tags/array.md)
