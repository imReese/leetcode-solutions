# 1534. 统计好三元组 (Count Good Triplets)

[LeetCode 原题链接](https://leetcode.cn/problems/count-good-triplets/) | 难度: **简单** | 标签: `数组`、`枚举`

## 题目描述

给你一个整数数组 `arr`, 以及 `a`、`b` 、`c` 三个整数. 请你统计其中好三元组的数量.

如果三元组 `(arr[i], arr[j], arr[k])` 满足下列全部条件, 则认为它是一个 **好三元组**.

- `0 <= i < j < k < arr.length`
- `|arr[i] - arr[j]| <= a`
- `|arr[j] - arr[k]| <= b`
- `|arr[i] - arr[k]| <= c`

其中 `|x|` 表示 `x` 的绝对值.

返回 **好三元组的数量**.

示例:

```plaintext
输入: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
输出: 4
解释: 一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
```

## 解法思路

### 枚举

- 核心思想: 三重循环枚举每种情况判断是否为好三元组 也可以遍历jk 通过一个数组维护在j之前满足a[j]±a且a[k]±c i的个数
- 时间复杂度: O(n³)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n = arr.size();
            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            res++;
                        }
                    }
                }
            }
            return res;
        }
};
```

## 相似题目

- [1995. 统计特殊四元组](https://leetcode.cn/problems/count-special-quadruplets/)

## Tags

[数组](/tags/array.md) | [枚举](/tags/enumeration.md)
