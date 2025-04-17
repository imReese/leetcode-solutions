# 4. 寻找两个正序数组的中位数 (Median of Two Sorted Arrays)

[LeetCode 原题链接](https://leetcode.cn/problems/median-of-two-sorted-arrays/) | 难度: **困难** | 标签: `数组`、`二分查找`、`分治`

## 题目描述

给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`. 请你找出并返回这两个正序数组的 **中位数**.

算法的时间复杂度应该为 `O(log (m+n))`.

示例:

```plaintext
输入: nums1 = [1,3], nums2 = [2]
输出: 2.00000
解释: 合并数组 = [1,2,3], 中位数 2
```

## 解法思路

### 方法一: 合并数组

- 核心思想: 合并两个数组, 然后取中位数
- 时间复杂度: O(m+n), 其中 m 和 n 分别是两个数组的长度.
- 空间复杂度: O(m+n)

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()

        n = len(nums)
        return nums[n//2] if n % 2 == 1 else (nums[n//2] + nums[n//2-1])/ 2.0
```

### 方法二: 二分查找

- 核心思想: 寻找中文数就是寻找合数组中下标为 `(m+n)/2` 和 `(m+n)/2-1` 的元素. 可以通过二分查找的方式排除nums1和nums2中前一部分元素来确定中位数
- 时间复杂度: O(log(min(m, n))), 其中 m 和 n 分别是两个数组的长度.
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
            int m = nums1.size();
            int n = nums2.size();
            int index1 = 0, index2 = 0;
            while (true) {
                if (index1 == m) {
                    return nums2[index2 + k - 1];
                }
                if (index2 == n) {
                    return nums1[index1 + k - 1];
                }
                if (k == 1) {
                    return min(nums1[index1], nums2[index2]);
                }
                int newIndex1 = min(index1 + k / 2 - 1, m - 1);
                int newIndex2 = min(index2 + k / 2 - 1, n - 1);
                int pivot1 = nums1[newIndex1];
                int pivot2 = nums2[newIndex2];
                if (pivot1 <= pivot2) {
                    k -= newIndex1 - index1 + 1;
                    index1 = newIndex1 + 1;
                } else {
                    k -= newIndex2 - index2 + 1;
                    index2 = newIndex2 + 1;
                }
            }
        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int total_len = nums1.size() + nums2.size();
            if (total_len % 2 == 1) {
                return getKthElement(nums1, nums2, (total_len + 1) / 2);
            } else {
                return (getKthElement(nums1, nums2, total_len / 2) + getKthElement(nums1, nums2, total_len / 2 + 1)) / 2.0;
            }
        }
};
```

## 相似题目

- [2387. 行排序矩阵的中位数](https://leetcode.cn/problems/median-of-a-row-wise-sorted-matrix/)

## Tags

[数组](/tags/array.md) | [二分查找](/tags/binary-search.md) | [分治](/tags/divide-and-conquer.md)
