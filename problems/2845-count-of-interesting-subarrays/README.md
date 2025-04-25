# 2845. 统计趣味子数组的数目 (Count of Interesting Subarrays)

[LeetCode 原题链接](https://leetcode.cn/problems/count-of-interesting-subarrays/) | 难度: **中等** | 标签: `数组`、`哈希表`、`前缀和`

## 题目描述

给你一个下标从 **0** 开始的整数数组 `nums`, 以及整数 `modulo` 和整数 `k`.

请你找出并统计数组中 **趣味子数组** 的数目.

如果 **子数组** `nums[l..r]` 满足下述条件, 则称其为 **趣味子数组**:

- 在范围 `[l, r]` 内, 设 `cnt` 为满足 `nums[i] % modulo == k` 的索引 `i` 的数量. 并且 `cnt % modulo == k`.

以整数形式表示并返回趣味子数组的数目.

**注意:** 子数组是数组中的一个连续非空的元素序列.

示例:

```plaintext
输入: nums = [3,2,4], modulo = 2, k = 1
输出：3
解释: 在这个示例中, 趣味子数组分别是:
    子数组 nums[0..0], 也就是 [3].
    - 在范围 [0, 0] 内, 只存在 1 个下标 i = 0 满足 nums[i] % modulo == k.
    - 因此 cnt = 1, 且 cnt % modulo == k.
    子数组 nums[0..1], 也就是 [3,2].
    - 在范围 [0, 1] 内, 只存在 1 个下标 i = 0 满足 nums[i] % modulo == k.
    - 因此 cnt = 1, 且 cnt % modulo == k.
    子数组 nums[0..2], 也就是 [3,2,4].
    - 在范围 [0, 2] 内, 只存在 1 个下标 i = 0 满足 nums[i] % modulo == k.
    - 因此 cnt = 1, 且 cnt % modulo == k.
    可以证明不存在其他趣味子数组. 因此, 答案为 3.
```

## 解法思路

### 前缀和

- 核心思想:
  - prefix表示当前位置符合 `nums[i] % modulo == k` 的元素个数
  - 对于子数组 `[l, r]`, 需要满足 `(prefix[r] - prefix[l]) % modulo == k`
  - 等价于寻找 `pre_sum[l] % modulo = (pre_sum[r] - k + modulo) % modulo`
  - `cnt[(prefix - k + modulo) % modulo]` 记录了之前出现过的符合条件的前缀和个数
  - 遍历 `r` 时, 可根据此时的 `prefix` 在哈希表cnt中快速找到符合条件的 `l` 的个数 并记录此时的 `prefix % modulo`
- 时间复杂度: O(n)
- 空间复杂度: O(min(n, modulo))

```cpp
class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            int n = nums.size();
            unordered_map<int, int> cnt;
            long long res = 0;
            int prefix = 0;
            cnt[0] = 1;
            for (int i = 0; i < n; i++) {
                prefix += (nums[i] % modulo == k);
                res += cnt[(prefix - k + modulo) % modulo];
                cnt[prefix % modulo]++;
            }
            return res;
        }
};
```

## 相似题目

- [974. 和可被 K 整除的子数组](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [前缀和](/tags/prefix-sum.md)
