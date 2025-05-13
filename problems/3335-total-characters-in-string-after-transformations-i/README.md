# 3335. 字符串转换后的长度 I (Total Characters in String After Transformations I)

[LeetCode 原题链接](https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/) | 难度: **中等** | 标签: `哈希表`、`数学`、`字符串`、`动态规划`、`计数`

## 题目描述

给你一个字符串 `s` 和一个整数 `t`, 表示要执行的 **转换** 次数. 每次 **转换** 需要根据以下规则替换字符串 `s` 中的每个字符:

- 如果字符是 `'z'`, 则将其替换为字符串 `"ab"`.
- 否则, 将其替换为字母表中的 **下一个** 字符. 例如, `'a'` 替换为 `'b'`, `'b'` 替换为 `'c'`, 依此类推.

返回**恰好** 执行 `t` 次转换后得到的字符串的 **长度**.

由于答案可能非常大, 返回其对 `109 + 7` 取余的结果.

示例:

```plaintext
输入: s = "abcyy", t = 2

输出: 7

解释:
  * 第一次转换 (t = 1)
    * 'a' 变为 'b'
    * 'b' 变为 'c'
    * 'c' 变为 'd'
    * 'y' 变为 'z'
    * 'y' 变为 'z'
    * 第一次转换后的字符串为: "bcdzz"
  * 第二次转换 (t = 2)
    * 'b' 变为 'c'
    * 'c' 变为 'd'
    * 'd' 变为 'e'
    * 'z' 变为 "ab"
    * 'z' 变为 "ab"
    * 第二次转换后的字符串为: "cdeabab"
  * 最终字符串长度: 字符串为 "cdeabab", 长度为 7 个字符.
```

## 解法思路

### 动态规划

- 核心思想: 首先对s各字符计数, 然后对每个字符的次数进行动态规划 首先prev[c]表示字符c在0次转换时贡献长度为1 curr[c]表示字符c经过当前次数转换后的贡献长度
- 时间复杂度: O(26*t)
- 空间复杂度: O(26)

```cpp
const int MOD = 1e9 + 7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26, 0);
        for (char& c : s) {
            cnt[c - 'a']++;
        }
        vector<long long> prev(26, 1);
        for (int k = 1; k <= t; k++) {
            vector<long long> curr(26, 0);
            for (int c = 0; c < 26; c++) {
                if (c != 25) {
                    current[c] = prev[c+1] % MOD;
                } else {
                    current[c] = (prev[0] + prev[1]) % MOD;
                }
            }
            prev = curr;
        }
        long long res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + cnt[i] * prev[i]) % MOD;
        }
        return res;
    }
};
```

## Tags

[哈希表](/tags/hash-table.md) | [数学](/tags/math.md) | [字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md) | [计数](/tags/counting.md)
