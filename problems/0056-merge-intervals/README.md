# 56. 合并区间 (Merge Intervals)

[LeetCode 原题链接](https://leetcode.cn/problems/merge-intervals/) | 难度: **中等** | 标签: `数组`、`排序`

## 题目描述

以数组 `intervals` 表示若干个区间的集合, 其中单个区间为 `intervals[i] = [starti, endi]`. 请你合并所有重叠的区间, 并返回 _一个不重叠的区间数组, 该数组需恰好覆盖输入中的所有区间_.

示例:

```plaintext
输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

## 解法思路

### 排序 + 遍历

- 时间复杂度: O(nlogn), 主要是排序的时间复杂度.
- 空间复杂度: O(n)

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
```

## 相似题目

- [57. 插入区间](https://leetcode.cn/problems/insert-interval/)

## Tags

[数组](/tags/array.md) | [排序](/tags/sorting.md)
