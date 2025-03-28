# 2080. 区间内查询数字的频率 (Range Frequency Queries)

[LeetCode 原题链接](https://www.leetcode.cn/problems/range-frequency-queries/) | 难度: **中等** | 标签: `设计`、`线段树`、`数组`、`哈希表`、`二分查找`

## 题目描述

请你设计一个数据结构，它能求出给定子数组内一个给定值的 **频率**  。

子数组中一个值的 **频率**  指的是这个子数组中这个值的出现次数。

请你实现 `RangeFreqQuery` 类：

  * `RangeFreqQuery(int[] arr)` 用下标从 **0**  开始的整数数组 `arr` 构造一个类的实例。
  * `int query(int left, int right, int value)` 返回子数组 `arr[left...right]` 中 `value` 的 **频率**  。

一个 **子数组** 指的是数组中一段连续的元素。`arr[left...right]` 指的是 `nums` 中包含下标 `left` 和 `right` **在内**  的中间一段连续元素。

 

**示例 1：**
[code] 
    **输入：**
    ["RangeFreqQuery", "query", "query"]
    [[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
    **输出：**
    [null, 1, 2]
    
    **解释：**
    RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
    rangeFreqQuery.query(1, 2, 4); // 返回 1 。4 在子数组 [33, 4] 中出现 1 次。
    rangeFreqQuery.query(0, 11, 33); // 返回 2 。33 在整个子数组中出现 2 次。
    
[/code]

 

**提示：**

  * `1 <= arr.length <= 105`
  * `1 <= arr[i], value <= 104`
  * `0 <= left <= right < arr.length`
  * 调用 `query` 不超过 `105` 次。

## 解法思路

```cpp
class RangeFreqQuery {
    private:
        vector<vector<int>> index;
    public:
        RangeFreqQuery(vector<int>& arr) {
            index.resize(100001);
            for (int i = 0; i < arr.size(); i++) {
                index[arr[i]].push_back(i);
            }
        }
        int query(int left, int right, int value) {
            auto& positions = index[value];
            auto l = lower_bound(positions.begin(), positions.end(), left);
            auto r = upper_bound(positions.begin(), positions.end(), right);
            return r - l;
        }
};
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
```
