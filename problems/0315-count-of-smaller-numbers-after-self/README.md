# 315. 计算右侧小于当前元素的个数 (Count of Smaller Numbers After Self)

[LeetCode 原题链接](https://leetcode.cn/problems/count-of-smaller-numbers-after-self/) | 难度: **困难** | 标签: `树状数组`、`线段树`、`数组`、`二分查找`、`分治`、`有序集合`、`归并排序`

## 题目描述

给你一个整数数组 _`nums`_, 按要求返回一个新数组 _`counts`_. 数组 `counts` 有该性质: `counts[i]` 的值是 `nums[i]` 右侧小于 `nums[i]` 的元素的数量.

示例:

```plaintext
输入: nums = [5,2,6,1]
输出: [2,1,1,0] 
解释:
    5 的右侧有 2 个更小的元素 (2 和 1)
    2 的右侧仅有 1 个更小的元素 (1)
    6 的右侧有 1 个更小的元素 (1)
    1 的右侧有 0 个更小的元素
```

## 解法思路

### 离散化树状数组

- 核心思想: 首先将原数组中的元素进行一个映射来减少空间占用, 维护一个树状数组来动态记录前缀和, 倒序遍历原数组查询树状数组的前缀和并更新树状数组
- 时间复杂度: O(nlogn)
- 空间复杂度: O(n)

```cpp
class Solution {
    private:
        vector<int> c;
        vector<int> a;
        void Init(int length) {
            c.resize(length, 0);
        }
        int LowBit(int x) {
            return x & (-x);
        }
        void Update(int pos) {
            while (pos < c.size()) {
                c[pos]++;
                pos += LowBit(pos);
            }
        }
        int Query(int pos) {
            int ret = 0;
            while (pos > 0) {
                ret += c[pos];
                pos -= LowBit(pos);
            }
            return ret;
        }
        void Discretization(vector<int>& nums) {
            a.assign(nums.begin(), nums.end());
            sort(a.begin(), a.end());
            a.erase(unique(a.begin(), a.end()), a.end());
        }
        int GetId(int x) {
            return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
        }
        public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> resultList;
            int n = nums.size();
            Discretization(nums);
            Init(n);
            for (int i = n - 1; i >= 0; i--) {
                int id = GetId(nums[i]);
                resultList.push_back(Query(id - 1));
                Update(id);
            }
            reverse(resultList.begin(), resultList.end());
            return resultList;
        }
};
```

## 相似题目

- [1649. 通过指令创建有序数组](https://leetcode.cn/problems/create-sorted-array-through-instructions/)

## Tags

[树状数组](/tags/binary-indexed-tree.md) | [线段树](/tags/segment-tree.md) | [数组](/tags/array.md) | [二分查找](/tags/binary-search.md) | [分治](/tags/divide-and-conquer.md) | [有序集合](/tags/ordered-set.md) | [归并排序](/tags/merge-sort.md)
