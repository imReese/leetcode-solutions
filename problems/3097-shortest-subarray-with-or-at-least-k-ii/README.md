# 3097. 或值至少为 K 的最短子数组 II (Shortest Subarray With OR at Least K II)

[LeetCode 原题链接](https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/) | 难度: **中等** | 标签: `位运算`、`数组`、`滑动窗口`

## 题目描述

给你一个 非负 整数数组 `nums` 和一个整数 `k`.

如果一个数组中所有元素的按位或运算 `OR` 的值 至少 为 `k`, 那么我们称这个数组是 特别的.

请你返回 `nums` 中 最短特别非空 子数组的长度, 如果特别子数组不存在, 那么返回 `-1`.

示例:

```plaintext
输入: nums = [1,2,3], k = 2
输出: 1
解释: 子数组 [3] 的按位 `OR` 值为 `3`, 所以我们返回 `1`.
```

## 解法思路

### 左右指针

- 核心思想: 固定右指针, 移动左指针, 直到左指针无法移动为止. 每次移动右指针后更新bits数, 然后尝试移动左指针
- 时间复杂度: O(nlogU) n是nums长度, U是nums中最大数
- 空间复杂度: O(logU)

```cpp
class Solution {
    public:
        int minimumSubarrayLength(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> bits(30);
            auto calc = [](vector<int>& bits) -> int {
                int ans = 0;
                for (int i = 0; i < bits.size(); i++) {
                    if (bits[i] > 0) {
                        ans |= 1 << i;
                    }
                }
                return ans;
            };
            int res = INT_MAX;
            for (int left = 0, right = 0; right < n; right++) {
                for (int i = 0; i < 30; i++) {
                    bits[i] += (nums[right] >> i) & 1;
                }
                while (left <= right && calc(bits) >= k) {
                    res = min(res, right - left + 1);
                    for (int i = 0; i < 30; i++) {
                        bits[i] -= (nums[left] >> i) & 1;
                    }
                    left++;
                }
            }
            return res == INT_MAX ? -1: res;
        }
};
```

## 相似题目

- [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/)

## Tags

[位运算](/tags/bit-manipulation.md) | [数组](/tags/array.md) | [滑动窗口](/tags/sliding-window.md)
