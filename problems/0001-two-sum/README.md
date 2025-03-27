# 1. 两数之和 (Two Sum)

[LeetCode 原题链接](https://leetcode.cn/problems/two-sum/) | 难度: **简单** | 标签: `数组`、`哈希表`

## 题目描述

给定一个整数数组 `nums` 和一个整数目标值 `target`, 请你在该数组中找出 **和为目标值** _`target`_ 的那 **两个** 整数, 并返回它们的数组下标.

你可以假设每种输入只会对应一个答案, 并且你不能使用两次相同的元素.

示例:

```plaintext
输入: nums = [2,7,11,15], target = 9
输出: [0, 1]
解释: nums[0] + nums[1] = 2 + 7 = 9, 返回[0, 1]
```

## 解法思路

### 方法一: 暴力枚举

- 核心思想: 遍历数组中所有可能的两数组合, 检查它们的和是否等于 target.
- 时间复杂度: O(n²)
- 空间复杂度: O(1)

``` python
# solution.py
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
```

### 方法二: 哈希表映射（最优解）

- 核心思想: 用哈希表存储已遍历元素的值与索引, 实现 O(1) 时间复杂度的差值查询.
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```python
# solution.py
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in hashmap:
                return [hashmap[complement], i]
            hashmap[num] = i
```

### 复杂度对比

| 方法 | 时间复杂度 | 空间复杂度 | 适用场景 |
| ----- | ----- | ----- | ----- |
| 暴力枚举 | O(n²) | O(1) | 小规模数据 |
| 哈希表映射 | O(n) | O(n) | 大规模数据 |

### 关键点

哈希表解法中需要先查询后存储, 避免同一元素被重复使用

```python
# 正确顺序: 先检查 complement 是否存在
if complement in hashmap:
    return [...]
hashmap[num] = i  # 后存储当前元素
```

## 相似题目

- [15. 三数之和](https://leetcode.cn/problems/3sum/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md)
