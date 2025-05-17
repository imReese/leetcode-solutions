# 347. 前 K 个高频元素 (Top K Frequent Elements)

[LeetCode 原题链接](https://leetcode.cn/problems/top-k-frequent-elements/) | 难度: **中等** | 标签: `数组`、`哈希表`、`分治`、`桶排序`、`计数`、`快速选择`、`排序`、`堆（优先队列）`

## 题目描述

给你一个整数数组 `nums` 和一个整数 `k`, 请你返回其中出现频率前 `k` 高的元素. 你可以按 **任意顺序** 返回答案.

示例:

```plaintext
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

## 解法思路

### 哈希表+小根堆

- 核心思想: 首先用哈希表统计每个元素的频率, 然后用小根堆维护频率前 `k` 高的元素.
- 时间复杂度: O(nlogk)
- 空间复杂度: O(n) 哈希表存储O(n)个元素, 小根堆存储O(k)个元素

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto& [num, cnt] : freq) {
            minHeap.push({cnt, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

## 相似题目

- [215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [分治](/tags/divide-and-conquer.md) | [桶排序](/tags/bucket-sort.md) | [计数](/tags/counting.md) | [快速选择](/tags/quick-select.md) | [排序](/tags/sorting.md) | [堆（优先队列）](/tags/heap-priority-queue.md)
