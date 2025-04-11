# 2999. 统计强大整数的数目 (Count the Number of Powerful Integers)

[LeetCode 原题链接](https://leetcode.cn/problems/count-the-number-of-powerful-integers/) | 难度: **困难** | 标签: `数学`、`字符串`、`动态规划`

## 题目描述

给你三个整数 `start`, `finish` 和 `limit`. 同时给你一个下标从 0 开始的字符串 `s`, 表示一个 正 整数.

如果一个 正 整数 `x` 末尾部分是 `s` （换句话说，`s` 是 `x` 的 后缀）, 且 `x` 中的每个数位至多是 `limit`, 那么我们称 `x` 是 强大的.

请你返回区间 `[start..finish]` 内强大整数的 总数目.

如果一个字符串 `x` 是 `y` 中某个下标开始（包括 `0` ）, 到下标为 `y.length - 1` 结束的子字符串, 那么我们称 `x` 是 `y` 的一个后缀. 比方说, `25` 是 `5125` 的一个后缀, 但不是 `512` 的后缀.

示例:

```plaintext
输入: start = 1, finish = 6000, limit = 4, s = "124"
输出: 5
解释: 区间 [1..6000] 内的强大数字为 124, 1124, 2124, 3124 和 4124. 这些整数的各个数位都 <= 4 且 "124" 是它们的后缀. 注意 5124 不是强大整数, 因为第一个数位 5 大于 4.
    这个区间内总共只有这 5 个强大整数.
```

## 解法思路

### 组合数学

- 核心思想: 计数函数calculate(x) 来计算小于等于x中满足limit且后缀为s的数字量, 答案即为calculate(finish) - calculate(start-1)
- 时间复杂度: O(log(finish))
- 空间复杂度: O(log(finish))

```cpp
class Solution {
    public:
        long long calculate(string x, string s, int limit) {
            if (x.length() < s.length()) {
                return 0;
            }
            if (x.length() == s.length()) {
                return x >= s ? 1 : 0;
            }
            string suffix = x.substr(x.length() - s.length(), s.length());
            long long count = 0;
            int preLen = x.length() - s.length();
            for (int i = 0; i < preLen; i++) {
                if (limit < (x[i] - '0')) {
                    count += (long)pow(limit + 1, preLen - i);
                    return count;
                }
                count += (long)(x[i] - '0') * (long)pow(limit + 1, preLen - 1 - i);
            }
            if (suffix >= s) {
                count++;
            }
            return count;
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string start_ = to_string(start - 1), finish_ = to_string(finish);
            return calculate(finish_, s, limit) - calculate(start_, s, limit);
        }
};
```

## 相似题目

- [970. 强整数](https://leetcode.cn/problems/powerful-integers/)

## Tags

[数学](/tags/math.md) | [字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md)
