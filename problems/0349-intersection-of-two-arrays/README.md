# 349. 两个数组的交集 (Intersection of Two Arrays)

[LeetCode 原题链接](https://leetcode.cn/problems/intersection-of-two-arrays/) | 难度: **简单** | 标签: `数组`、`哈希表`、`双指针`、`二分查找`、`排序`

## 题目描述

给定两个数组 `nums1` 和 `nums2`, 返回 它们的交集. 输出结果中的每个元素一定是 唯一 的. 我们可以 不考虑输出结果的顺序.

示例:

```plaintext
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
```

## 解法思路

### 哈希表

- 核心思想: 用哈希表存储其中数组的元素, 主要是去重, 然后对哈希表取交集.
- 时间复杂度: O(m+n)
- 空间复杂度: O(m+n)

```cpp
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            unordered_set<int> set1(nums1.begin(), nums1.end());
            unordered_set<int> set2(nums2.begin(), nums2.end());
            for (auto num : set1) {
                if (set2.find(num) != set2.end()) {
                    res.push_back(num);
                }
            }
            return res;
        }
};
```

## 相似题目

- [350. 两个数组的交集 II](https://leetcode.cn/problems/intersection-of-two-arrays-ii/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [双指针](/tags/two-pointers.md) | [二分查找](/tags/binary-search.md) | [排序](/tags/sorting.md)
