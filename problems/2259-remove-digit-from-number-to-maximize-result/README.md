# 2259. 移除指定数字得到的最大结果 (Remove Digit From Number to Maximize Result)

[LeetCode 原题链接](https://leetcode-cn.com/problems/remove-digit-from-number-to-maximize-result/) | 难度: **简单** | 标签: `贪心`、`字符串`、`枚举`

## 题目描述

给你一个表示某个正整数的字符串 `number` 和一个字符 `digit` 。

从 `number` 中 **恰好** 移除 **一个** 等于 `digit` 的字符后，找出并返回按 **十进制** 表示 **最大** 的结果字符串。生成的测试用例满足 `digit` 在 `number` 中出现至少一次。

 

**示例 1：**
[code] 
    **输入：** number = "123", digit = "3"
    **输出：** "12"
    **解释：** "123" 中只有一个 '3' ，在移除 '3' 之后，结果为 "12" 。
    
[/code]

**示例 2：**
[code] 
    **输入：** number = "1231", digit = "1"
    **输出：** "231"
    **解释：** 可以移除第一个 '1' 得到 "231" 或者移除第二个 '1' 得到 "123" 。
    由于 231 > 123 ，返回 "231" 。
    
[/code]

**示例 3：**
[code] 
    **输入：** number = "551", digit = "5"
    **输出：** "51"
    **解释：** 可以从 "551" 中移除第一个或者第二个 '5' 。
    两种方案的结果都是 "51" 。
    
[/code]

 

**提示：**

  * `2 <= number.length <= 100`
  * `number` 由数字 `'1'` 到 `'9'` 组成
  * `digit` 是 `'1'` 到 `'9'` 中的一个数字
  * `digit` 在 `number` 中出现至少一次

## 解法思路

```cpp
class Solution {
    public:
        string removeDigit(string number, char digit) {
            string result = "";
            int n = number.length();
            for (int i = 0; i < n; i++) {
                if (number[i] == digit) {
                    string candidate = number.substr(0, i) + number.substr(i + 1);
                    if (candidate > result) {
                        result = candidate;
                    }
                }
            }
            return result;
        }
};
class Solution {
    public:
        string removeDigit(string number, char digit) {
            int n = number.length();
            int lastIndex = -1;
            for (int i = 0; i < n - 1; i++) {
                if (number[i] == digit) {
                    if (number[i] < number[i + 1]) {
                        return number.substr(0, i) + number.substr(i + 1);
                    }
                    lastIndex = i;
                }
            }
            if (number[n - 1] == digit || lastIndex == -1) {
                return number.substr(0, n - 1);
            }
            return number.substr(0, lastIndex) + number.substr(lastIndex + 1);
        }
};
```
