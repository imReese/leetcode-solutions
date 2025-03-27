# 2712. 使所有字符相等的最小成本 (Minimal Cost to Make All Characters Equal)

[LeetCode 原题链接](https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/) | 难度: **中等** | 标签: `贪心`、`字符串`、`动态规划`

## 题目描述

给你一个下标从 0 开始、长度为 n 的二进制字符串 s , 你可以对其执行两种操作:

选中一个下标 i 并且反转从下标 0 到下标 i(包括下标 0 和下标 i )的所有字符, 成本为 i + 1 .
选中一个下标 i 并且反转从下标 i 到下标 n - 1(包括下标 i 和下标 n - 1 )的所有字符, 成本为 n - i .
返回使字符串内所有字符 相等 需要的 最小成本 .

反转 字符意味着: 如果原来的值是 '0' , 则反转后值变为 '1' , 反之亦然.

示例:

```plaintext
输入: s = "0011"
输出: 2
解释: 执行第二种操作, 选中下标 i = 2 , 可以得到 s = "0000" , 成本为 2 . 可以证明 2 是使所有字符相等的最小成本.
```

## 解法思路

### 贪心+一次遍历

- 核心思想: 一次遍历, 相邻字符不相等则选择成本较小的一侧, 翻转不影响相邻字符的相等关系
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
// solution.cpp
class Solution {
    public:
        long long minimumCost(string s) {
            int len = s.size();
            long long cost = 0;
            for (int i = 1; i < len; i++) {
                if (s[i] != s[i - 1]) {
                    cost += min(i, len - i);
                }
            }
            return cost;
        }
};
```

### 关键点

```plaintxt
因为不管反转那一侧, 下标为i均被反转
'10110' 选择下标为2右侧反转为 '10001'. 下标为2和下标为3在反转前后均相等, 下标为3和下标为4在反转前后均不等
```

## 相似题目

- [926. 将字符串翻转到单调递增](https://leetcode.cn/problems/flip-string-to-monotone-increasing/)
