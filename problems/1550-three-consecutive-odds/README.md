# 1550. 存在连续三个奇数的数组 (Three Consecutive Odds)

[LeetCode 原题链接](https://leetcode.cn/problems/three-consecutive-odds/) | 难度: **简单** | 标签: `数组`

## 题目描述

给你一个整数数组 `arr`, 请你判断数组中是否存在连续三个元素都是奇数的情况: 如果存在, 请返回 `true`; 否则, 返回 `false`.

示例:

```plaintext
输入: arr = [2,6,4,1]
输出: false
解释: 不存在连续三个元素都是奇数的情况.
```

## 解法思路

### 枚举

- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= n - 3; i++) {
            if ((arr[i] & 1) && (arr[i+1] & 1) && (arr[i+2] & 1)) {
                return true;
            }
        }
        return false;
    }
};
```

## Tags

[数组](/tags/array.md)
