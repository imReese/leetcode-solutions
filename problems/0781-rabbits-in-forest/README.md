# 781. 森林中的兔子 (Rabbits in Forest)

[LeetCode 原题链接](https://leetcode.cn/problems/rabbits-in-forest/) | 难度: **中等** | 标签: `贪心`、`数组`、`哈希表`、`数学`

## 题目描述

森林中有未知数量的兔子. 提问其中若干只兔子 **"还有多少只兔子与你（指被提问的兔子）颜色相同?"**, 将答案收集到一个整数数组 `answers` 中, 其中 `answers[i]` 是第 `i` 只兔子的回答.

给你数组 `answers`, 返回森林中兔子的最少数量.

示例:

```plaintext
输入: answers = [1,1,2]
输出: 5
解释:
    两只回答了 "1" 的兔子可能有相同的颜色, 设为红色.
    之后回答了 "2" 的兔子不会是红色, 否则他们的回答会相互矛盾.
    设回答了 "2" 的兔子为蓝色.
    此外, 森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中.
    因此森林中兔子的最少数量是 5 只: 3 只回答的和 2 只没有回答的.
```

## 解法思路

### 贪心

- 核心思路: 如果有兔子回答了 `x`, 那么一定存在 `x + 1` 只兔子是同一种颜色的. 也会存在两只红色 两只蓝色 此时 `answer` 为 `[1,1,1,1]` 故当哈希表中`cnt[ans] == ans + 1` 需要将 `cnt[ans]` 置为 0, 重新开始计数.
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int res = 0;
            unordered_map<int, int> cnt;
            for (int ans : answers) {
                if (cnt[ans] == 0) {
                    res += ans + 1;
                }
                cnt[ans]++;
                if (cnt[ans] == ans + 1) {
                    cnt[ans] = 0;
                }
            }
            return res;
        }
};
```

## Tags

[贪心](/tags/greedy.md) | [数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [数学](/tags/math.md)
