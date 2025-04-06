# 1863. 找出所有子集的异或总和再求和 (Sum of All Subset XOR Totals)

[LeetCode 原题链接](https://leetcode.cn/problems/sum-of-all-subset-xor-totals/) | 难度: **简单** | 标签: `位运算`、`数组`、`数学`、`回溯`、`组合数学`、`枚举`

## 题目描述

一个数组的 异或总和 定义为数组中所有元素按位 `XOR` 的结果；如果数组为 空, 则异或总和为 `0`.

- 例如, 数组 `[2,5,6]` 的 异或总和 为 `2 XOR 5 XOR 6 = 1`.

给你一个数组 `nums`, 请你求出 `nums` 中每个 子集 的 异或总和, 计算并返回这些值相加之 和.

注意:在本题中, 元素 相同 的不同子集应 多次 计数.

数组 `a` 是数组 `b` 的一个 子集 的前提条件是: 从 `b` 删除几个（也可能不删除）元素能够得到 `a`.

示例:

```plaintext
输入: nums = [1,3]
输出: 6
解释: [1,3] 共有 4 个子集: 
    - 空子集的异或总和是 0.
    - [1] 的异或总和为 1.
    - [3] 的异或总和为 3.
    - [1,3] 的异或总和为 1 XOR 3 = 2.
    0 + 1 + 3 + 2 = 6
```

## 解法思路

### 方法一: 递归法枚举所有子集

- 核心思想: 对nums中每个num都有选和不选两种情况, 递归枚举所有子集.
- 时间复杂度: O(2^n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int res;
        int n;
        void dfs(int val, int idx, vector<int>& nums) {
            if (idx == n) {
                res += val;
                return;
            }
            dfs(val ^ nums[idx], idx + 1, nums);
            dfs(val, idx + 1, nums);
        }
        int subsetXORSum(vector<int>& nums) {
            res = 0;
            n = nums.size();
            dfs(0, 0, nums);
            return res;        
        }
};
```

### 方法二: 数学法

- 核心思想: 对nums中每个num都有选和不选两种情况, 所有子集的异或总和等于所有子集的异或总和乘以2的nums.size()-1次方.
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```python
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for num in nums:
            res = res | num;
        return (res << (n - 1));
```

## Tags

[位运算](/tags/bit-manipulation.md) | [数组](/tags/array.md) | [数学](/tags/math.md)
