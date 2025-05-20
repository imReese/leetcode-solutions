# 3355. 零数组变换 I (Zero Array Transformation I)

[LeetCode 原题链接](https://leetcode.cn/problems/zero-array-transformation-i/) | 难度: **中等** | 标签: `数组`、`前缀和`

## 题目描述

给定一个长度为 `n` 的整数数组 `nums` 和一个二维数组 `queries`, 其中 `queries[i] = [li, ri]`.

对于每个查询 `queries[i]`:

- 在 `nums` 的下标范围 `[li, ri]` 内选择一个下标子集.
- 将选中的每个下标对应的元素值减 1.

**零数组** 是指所有元素都等于 0 的数组.

如果在按顺序处理所有查询后, 可以将 `nums` 转换为 **零数组**, 则返回 `true`, 否则返回 `false`.

示例:

```plaintext
输入: nums = [1,0,1], queries = [[0,2]]

输出: true

解释: 
  对于 i = 0:
    选择下标子集 `[0, 2]` 并将这些下标处的值减 1.
    数组将变为 `[0, 0, 0]`, 这是一个零数组.
```

## 解法思路

### 差分数组

- 时间复杂度: O(n + q) n是数组长度 q是查询数量
- 空间复杂度: O(n)

```cpp
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 2, 0);
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l]++;
            if (r + 1 < n) {
                diff[r+1]--;
            }
        }
        int prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += diff[i];
            if (nums[i] < 0 || prefix < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
```

## 相似题目

- [3489. 零数组变换 IV](https://leetcode.cn/problems/zero-array-transformation-iv/)

## Tags

[数组](/tags/array.md) | [前缀和](/tags/prefix-sum.md)
