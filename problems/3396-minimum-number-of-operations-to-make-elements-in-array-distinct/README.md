# 3396. 使数组元素互不相同所需的最少操作次数 (Minimum Number of Operations to Make Elements in Array Distinct)

[LeetCode 原题链接](https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/) | 难度: **简单** | 标签: `数组`、`哈希表`

## 题目描述

给你一个整数数组 `nums`, 你需要确保数组中的元素 互不相同. 为此, 你可以执行以下操作任意次:

- 从数组的开头移除 3 个元素. 如果数组中元素少于 3 个, 则移除所有剩余元素.

注意: 空数组也视作为数组元素互不相同. 返回使数组元素互不相同所需的 最少操作次数.

示例:

```plaintext
输入: nums = [1,2,3,4,2,3,3,5,7]

输出: 2

解释:

  * 第一次操作: 移除前 3 个元素, 数组变为 `[4, 2, 3, 3, 5, 7]`. 
  * 第二次操作: 再次移除前 3 个元素, 数组变为 `[3, 5, 7]`, 此时数组中的元素互不相同. 

因此, 答案是 2. 
```

## 解法思路

### 倒序遍历 + 哈希表

- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int res = 0;
            int n = nums.size();
            unordered_set<int> s;
            for (int i = n - 1; i >= 0; i--) {
                if (s.find(nums[i]) != s.end()) {
                    res = i / 3 + 1;
                    break;
                }
                s.insert(nums[i]);
            }
            return res;
        }
};
```

## 相似题目

- [945. 使数组唯一的最小增量](https://leetcode.cn/problems/minimum-increment-to-make-array-unique/)

## Tags

[数组](/tags/array.md) [哈希表](/tags/hash-table.md)
