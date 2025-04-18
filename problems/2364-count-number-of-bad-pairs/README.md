# 2364. 统计坏数对的数目 (Count Number of Bad Pairs)

[LeetCode 原题链接](https://leetcode.cn/problems/count-number-of-bad-pairs/) | 难度: **中等** | 标签: `数组`、`哈希表`、`数学`、`计数`

## 题目描述

给你一个下标从 **0** 开始的整数数组 `nums`. 如果 `i < j` 且 `j - i != nums[j] - nums[i]`, 那么我们称 `(i, j)` 是一个 **坏****数对**.

请你返回 `nums` 中 **坏数对** 的总数目.

示例:

```plaintext
输入: nums = [4,1,3,3]
输出: 5
解释: 数对 (0, 1) 是坏数对, 因为 1 - 0 != 1 - 4.
    数对 (0, 2) 是坏数对, 因为 2 - 0 != 3 - 4, 2 != -1.
    数对 (0, 3) 是坏数对, 因为 3 - 0 != 3 - 4, 3 != -1.
    数对 (1, 2) 是坏数对, 因为 2 - 1 != 3 - 1, 1 != 2.
    数对 (2, 3) 是坏数对, 因为 3 - 2 != 3 - 3, 1 != 0.
    总共有 5 个坏数对, 所以我们返回 5.
```

## 解法思路

### 哈希表

- 核心思想: 从前往后遍历数组 当遍历至`nums[i]`时 原本会增加i个数对, 减去哈希表中记录的非坏数对的个数就是新增的坏数对的个数
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long ans = 0;
            int n = nums.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++) {
                ans += i - mp[nums[i] - i];
                mp[nums[i] - i]++;
            }
            return ans;
        }
};
```

## 相似题目

- [532. 数组中的 k-diff 数对](https://leetcode.cn/problems/k-diff-pairs-in-an-array/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [数学](/tags/math.md) | [计数](/tags/counting.md)
