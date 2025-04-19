# 327. 区间和的个数 (Count of Range Sum)

[LeetCode 原题链接](https://leetcode.cn/problems/count-of-range-sum/) | 难度: **困难** | 标签: `树状数组`、`线段树`、`数组`、`二分查找`、`分治`、`有序集合`、`归并排序`

## 题目描述

给你一个整数数组 `nums` 以及两个整数 `lower` 和 `upper`. 求数组中, 值位于范围 `[lower, upper]` （包含 `lower` 和 `upper`）之内的 **区间和的个数**.

**区间和** `S(i, j)` 表示在 `nums` 中, 位置从 `i` 到 `j` 的元素之和, 包含 `i` 和 `j` (`i` ≤ `j`).

示例:

```plaintext
输入: nums = [-2,5,-1], lower = -2, upper = 2
输出: 3
解释: 存在三个区间: [0,0]、[2,2] 和 [0,2], 对应的区间和分别是: -2 、-1 、2.
```

## 解法思路

### 树状数组

- 核心思想:
  - 问题转换为寻找满足 `preSum[j] - upper ≤ preSum[i] ≤ preSum[j] - lower` 的 `i < j` 的个数
  - 将区间和转化为前缀和的差值, 通过离散化压缩数据范围, 并利用树状数组动态维护前缀和的分布, 从而高效统计满足条件的区间数量
- 时间复杂度: O(nlogn)
- 空间复杂度: O(n)

```cpp
class FenwickTree {
    private:
        vector<int> tree;
        int n;
    public:
        FenwickTree(int size) : n(size), tree(size + 1) {}
        void update(int index, int delta) {
            while (index <= n) {
                tree[index] += delta;
                index += index & -index;
            }
        }
        int query(int index) {
            int res = 0;
            while (index > 0) {
                res += tree[index];
                index -= index & -index;
            }
            return res;
        }
};
class Solution {
    public:
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            long long sum = 0;
            vector<long long> preSum = {0};
            for (int num : nums) {
                sum += num;
                preSum.push_back(sum);
            }
            vector<long long> allNumbers;
            for (long long x : preSum) {
                allNumbers.push_back(x);
                allNumbers.push_back(x - lower);
                allNumbers.push_back(x - upper);
            }
            sort(allNumbers.begin(), allNumbers.end());
            auto last = unique(allNumbers.begin(), allNumbers.end());
            allNumbers.erase(last, allNumbers.end());
            FenwickTree ft(allNumbers.size());
            int res = 0;
            for (long long s_val : preSum) {
                int left_idx = lower_bound(allNumbers.begin(), allNumbers.end(), s_val - upper) - allNumbers.begin() + 1;
                int right_idx = lower_bound(allNumbers.begin(), allNumbers.end(), s_val - lower) - allNumbers.begin() + 1;
                if (right_idx > 0 && left_idx <= right_idx) {
                    res += ft.query(right_idx) - (left_idx > 1 ? ft.query(left_idx - 1) : 0);
                }
                int s_pos = lower_bound(allNumbers.begin(), allNumbers.end(), s_val) - allNumbers.begin() + 1;
                ft.update(s_pos, 1);
            }
            return res;
        }
};
```

## 相似题目

- [315. 计算右侧小于当前元素的个数](https://leetcode.cn/problems/count-of-smaller-numbers-after-self/)

## Tags

[树状数组](/tags/binary-indexed-tree.md) | [线段树](/tags/segment-tree.md) | [数组](/tags/array.md) | [二分查找](/tags/binary-search.md) | [分治](/tags/divide-and-conquer.md) | [有序集合](/tags/sorted-set.md) | [归并排序](/tags/merge-sort.md)
