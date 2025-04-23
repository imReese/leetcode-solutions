# 2145. 统计隐藏数组数目 (Count the Hidden Sequences)

[LeetCode 原题链接](https://leetcode.cn/problems/count-the-hidden-sequences/) | 难度: **中等** | 标签: `数组`、`前缀和`

## 题目描述

给你一个下标从 **0** 开始且长度为 `n` 的整数数组 `differences`, 它表示一个长度为 `n + 1` 的 **隐藏** 数组 **相邻** 元素之间的 **差值**. 更正式的表述为: 我们将隐藏数组记作 `hidden`, 那么 `differences[i] = hidden[i + 1] - hidden[i]`.

同时给你两个整数 `lower` 和 `upper`, 它们表示隐藏数组中所有数字的值都在 **闭** 区间 `[lower, upper]` 之间.

- 比方说, `differences = [1, -3, 4]`, `lower = 1`, `upper = 6`, 那么隐藏数组是一个长度为 `4` 且所有值都在 `1` 和 `6` （包含两者）之间的数组.
  - `[3, 4, 1, 5]` 和 `[4, 5, 2, 6]` 都是符合要求的隐藏数组.
  - `[5, 6, 3, 7]` 不符合要求, 因为它包含大于 `6` 的元素.
  - `[1, 2, 3, 4]` 不符合要求, 因为相邻元素的差值不符合给定数据.

请你返回 **符合** 要求的隐藏数组的数目. 如果没有符合要求的隐藏数组, 请返回 `0`.

示例:

```plaintext
输入: differences = [1,-3,4], lower = 1, upper = 6
输出: 2
解释: 符合要求的隐藏数组为:
    - [3, 4, 1, 5]
    - [4, 5, 2, 6]
    所以返回 2.
```

## 解法思路

### 遍历确定上下界

- 核心思想: 假定原数组首位为0, 根据differences数组确定原数组的上下界, 符合要求的数组个数为 `(upper - lower) - (max_num - min_num) + 1`
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int num = 0;
            int min_num = 0;
            int max_num = 0;
            for (int d : differences) {
                num += d;
                min_num = min(num, min_num);
                max_num = max(num, max_num);
                if (max_num - min_num > upper - lower) {
                    return 0;
                }
            }
            int res = (upper - lower) - (max_num - min_num) + 1;
            return res;
        }
};
```

## Tags

[数组](/tags/array.md) | [前缀和](/tags/prefix-sum.md)
