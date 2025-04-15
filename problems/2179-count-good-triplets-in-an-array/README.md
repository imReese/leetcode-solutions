# 2179. 统计数组中好三元组数目 (Count Good Triplets in an Array)

[LeetCode 原题链接](https://leetcode.cn/problems/count-good-triplets-in-an-array/) | 难度: **困难** | 标签: `树状数组`、`线段树`、`数组`、`二分查找`、`分治`、`有序集合`、`归并排序`

## 题目描述

给你两个下标从 **0** 开始且长度为 `n` 的整数数组 `nums1` 和 `nums2`, 两者都是 `[0, 1, ..., n - 1]` 的 **排列**.

**好三元组** 指的是 `3` 个 **互不相同** 的值, 且它们在数组 `nums1` 和 `nums2` 中出现顺序保持一致. 换句话说, 如果我们将 `pos1v` 记为值 `v` 在 `nums1` 中出现的位置, `pos2v` 为值 `v` 在 `nums2` 中的位置, 那么一个好三元组定义为 `0 <= x, y, z <= n - 1`, 且 `pos1x < pos1y < pos1z` 和 `pos2x < pos2y < pos2z` 都成立的 `(x, y, z)`.

请你返回好三元组的 **总数目**.

示例:

```plaintext
输入: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
输出: 1
解释:
    总共有 4 个三元组 (x,y,z) 满足 pos1x < pos1y < pos1z, 分别是 (2,0,1), (2,0,3), (2,1,3) 和 (0,1,3).
    这些三元组中, 只有 (0,1,3) 满足 pos2x < pos2y < pos2z. 所以只有 1 个好三元组.
```

## 解法思路

### 树状数组

- 核心思想: 将nums2的元素值映射至其下标得到pos2 按nums2的顺序遍历元素 用树状数组维护当前已处理的元素在nums1中的位置
- 时间复杂度: O(nlogn)
- 空间复杂度: O(n)

```cpp
class FenwickTree {
    private:
        vector<int> tree;
    public:
        FenwickTree(int size) : tree(size + 1, 0) {}
        void update(int index, int delta) {
            index++;
            while (index < tree.size()) {
                tree[index] += delta;
                index += index & (-index);
            }
        }
        int query(int index) {
            index++;
            int res = 0;
            while (index > 0) {
                res += tree[index];
                index -= index & (-index);
            }
            return res;
        }
};

class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            vector<int> pos2(n), reversedIndexMapping(n);
            for (int i = 0; i < n; i++) {
                pos2[nums2[i]] = i;
            }
            for (int i = 0; i < n; i++) {
                reversedIndexMapping[pos2[nums1[i]]] = i;
            }
            FenwickTree tree(n);
            long long res = 0;
            for (int j = 0; j < n; j++) {
                int pos = reversedIndexMapping[j];
                int left = tree.query(pos);
                tree.update(pos, 1);
                int right = (n - 1 - pos) - (j - left);
                res += (long long)left * right;
            }
            return res;
        }
};
```

## 相似题目

- [315. 计算右侧小于当前元素的个数](https://leetcode.cn/problems/count-of-smaller-numbers-after-self/)

## Tags

[树状数组](/tags/binary-indexed-tree.md) | [线段树](/tags/segment-tree.md) | [数组](/tags/array.md) | [二分查找](/tags/binary-search.md) | [分治](/tags/divide-and-conquer.md) | [有序集合](/tags/sorted-set.md) | [归并排序](/tags/merge-sort.md)
