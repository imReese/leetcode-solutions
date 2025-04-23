# 1399. 统计最大组的数目 (Count Largest Group)

[LeetCode 原题链接](https://leetcode.cn/problems/count-largest-group/) | 难度: **简单** | 标签: `哈希表`、`数学`

## 题目描述

给你一个整数 `n`. 请你先求出从 `1` 到 `n` 的每个整数 10 进制表示下的数位和(每一位上的数字相加), 然后把数位和相等的数字放到同一个组中.

请你统计每个组中的数字数目, 并返回数字数目并列最多的组有多少个.

示例:

```plaintext
输入: n = 13
输出: 4
解释: 总共有 9 个组, 将 1 到 13 按数位求和后这些组分别是:
    [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. 总共有 4 个组拥有的数字并列最多.
```

## 解法思路

### 哈希表

- 核心思想: 从1到n遍历 计算每个数的数位和记录在哈希表中 最后遍历哈希表找到数位和最多的组的个数
- 时间复杂度: O(nlogn)
- 空间复杂度: O(logn)

```cpp
class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> mp;
            int maxSum = 0;
            for (int i = 1; i <= n; i++) {
                int key = 0, i0 = i;
                while (i0 > 0) {
                    key += i0 % 10;
                    i0 /= 10;
                }
                mp[key]++;
                maxSum = max(maxSum, mp[key]);
            }
            int ans = 0;
            for (auto& kvpair : mp) {
                if (kvpair.second == maxSum) {
                    ans++;
                }
            }
            return ans;
        }
};
```

## Tags

[哈希表](/tags/hash-table.md) | [数学](/tags/math.md)
