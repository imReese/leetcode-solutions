# 914. 卡牌分组 (X of a Kind in a Deck of Cards)

[LeetCode 原题链接](https://leetcode.cn/problems/x-of-a-kind-in-a-deck-of-cards/) | 难度: **简单** | 标签: `数组`、`哈希表`、`数学`、`计数`、`数论`

## 题目描述

给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 `X`，使我们可以将整副牌按下述规则分成 1 组或更多组：

  * 每组都有 `X` 张牌。
  * 组内所有的牌上都写着相同的整数。

仅当你可选的 `X >= 2` 时返回 `true`。

 

**示例 1：**
[code] 
    **输入：** deck = [1,2,3,4,4,3,2,1]
    **输出：** true
    **解释：** 可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
    
[/code]

**示例 2：**
[code] 
    **输入：** deck = [1,1,1,2,2,2,3,3]
    **输出：** false
    **解释：** 没有满足要求的分组。
    
[/code]

  
**提示：**

  * `1 <= deck.length <= 104`
  * `0 <= deck[i] < 104`

## 解法思路

```cpp
class Solution {
    public:
        bool hasGroupsSizeX(vector<int>& deck) {
            unordered_map<int, int> cnt;
            for (int i : deck) {
                cnt[i]++;
            }
            int x = 0;
            for (const auto& pair : cnt) {
                x = gcd(x, pair.second); 
            }
            return x >= 2;
        }
};
```
