# 2176. 统计数组中相等且可以被整除的数对 (Count Equal and Divisible Pairs in an Array)

[LeetCode 原题链接](https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/) | 难度: **简单** | 标签: `数组`

## 题目描述

给你一个下标从 **0** 开始长度为 `n` 的整数数组 `nums` 和一个整数 `k`, 请你返回满足 `0 <= i < j < n`, `nums[i] == nums[j]` 且 `(i * j)` 能被 `k` 整除的数对 `(i, j)` 的 **数目**.

示例:

```plaintext
输入: nums = [3,1,2,2,2,1,3], k = 2
输出: 4
解释:
    总共有 4 对数符合所有要求:
    - nums[0] == nums[6] 且 0 * 6 == 0, 能被 2 整除.
    - nums[2] == nums[3] 且 2 * 3 == 6, 能被 2 整除.
    - nums[2] == nums[4] 且 2 * 4 == 8, 能被 2 整除.
    - nums[3] == nums[4] 且 3 * 4 == 12, 能被 2 整除.
```

## 解法思路

### 双循环遍历

- 时间复杂度: O(n²)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            int cnt = 0;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if((nums[i] == nums[j]) && ((i * j) % k == 0)){
                        cnt++;
                    }
                }
            }
            return cnt;
        }
};
```

## 相似题目

- [2006. 差的绝对值为 K 的数对数目](https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k/)

## Tags

[数组](/tags/array.md)
