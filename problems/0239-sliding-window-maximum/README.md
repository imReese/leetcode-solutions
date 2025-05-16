# 239. 滑动窗口最大值 (Sliding Window Maximum)

[LeetCode 原题链接](https://leetcode.cn/problems/sliding-window-maximum/) | 难度: **困难** | 标签: `队列`、`数组`、`滑动窗口`、`单调队列`、`堆（优先队列）`

## 题目描述

给你一个整数数组 `nums`, 有一个大小为 _`k`_ 的滑动窗口从数组的最左侧移动到数组的最右侧. 你只可以看到在滑动窗口内的 `k` 个数字. 滑动窗口每次只向右移动一位.

返回 _滑动窗口中的最大值_.

示例:

```plaintext
输入: nums = [1,3,-1,-3,5,3,6,7], k = 3
输出: [3,3,5,5,6,7]
解释:
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7
```

## 解法思路

### 单调队列

- 核心思想: 维护一个单调递减的队列, 队列头部为最大值.
- 时间复杂度: O(n)
- 空间复杂度: O(k)

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
```

## 相似题目

- [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

## Tags

[队列](/tags/queue.md) | [数组](/tags/array.md) | [滑动窗口](/tags/sliding-window.md) | [单调队列](/tags/monotonic-queue.md) | [堆（优先队列）](/tags/heap-priority-queue.md)
