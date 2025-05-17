# 75. 颜色分类 (Sort Colors)

[LeetCode 原题链接](https://leetcode.cn/problems/sort-colors/) | 难度: **中等** | 标签: `数组`、`双指针`、`排序`

## 题目描述

给定一个包含红色、白色和蓝色、共 _`n`_ 个元素的数组 `nums`, **原地** 对它们进行排序, 使得相同颜色的元素相邻, 并按照红色、白色、蓝色顺序排列.

我们使用整数 `0`、 `1` 和 `2` 分别表示红色、白色和蓝色.

必须在不使用库内置的 sort 函数的情况下解决这个问题.

示例:

```plaintext
输入: nums = [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
```

## 解法思路

### 双指针

- 核心思想: 数组分为三个部分, 分别是 `0`、`1` 和 `2`, 使用两个指针 `p0` 和 `p1` 来维护当前 `0` 和 `1` 的边界.
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p1]);
                p1++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;
            }
        }
    }
};
```

## 相似题目

- [148. 排序链表](https://leetcode.cn/problems/sort-list/)

## Tags

[数组](/tags/array.md) | [双指针](/tags/two-pointers.md) | [排序](/tags/sort.md)
