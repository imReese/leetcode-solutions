# 3337. 字符串转换后的长度 II (Total Characters in String After Transformations II)

[LeetCode 原题链接](https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/) | 难度: **困难** | 标签: `哈希表`、`数学`、`字符串`、`动态规划`、`计数`

## 题目描述

给你一个由小写英文字母组成的字符串 `s`, 一个整数 `t` 表示要执行的 **转换** 次数, 以及一个长度为 26 的数组 `nums`. 每次 **转换** 需要根据以下规则替换字符串 `s` 中的每个字符:

- 将 `s[i]` 替换为字母表中后续的 `nums[s[i] - 'a']` 个连续字符. 例如, 如果 `s[i] = 'a'` 且 `nums[0] = 3`, 则字符 `'a'` 转换为它后面的 3 个连续字符, 结果为 `"bcd"`.
- 如果转换超过了 `'z'`, 则 **回绕** 到字母表的开头. 例如, 如果 `s[i] = 'y'` 且 `nums[24] = 3`, 则字符 `'y'` 转换为它后面的 3 个连续字符, 结果为 `"zab"`.

返回 **恰好** 执行 `t` 次转换后得到的字符串的 **长度**.

由于答案可能非常大, 返回其对 `109 + 7` 取余的结果.

示例:

```plaintext
输入: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

输出: 7

解释:
* 第一次转换 (t = 1)
    * 'a' 变为 'b' 因为 nums[0] == 1
    * 'b' 变为 'c' 因为 nums[1] == 1
    * 'c' 变为 'd' 因为 nums[2] == 1
    * 'y' 变为 'z' 因为 nums[24] == 1
    * 'y' 变为 'z' 因为 nums[24] == 1
    * 第一次转换后的字符串为: "bcdzz"
* 第二次转换 (t = 2)
    * 'b' 变为 'c' 因为 nums[1] == 1
    * 'c' 变为 'd' 因为 nums[2] == 1
    * 'd' 变为 'e' 因为 nums[3] == 1
    * 'z' 变为 'ab' 因为 nums[25] == 2
    * 'z' 变为 'ab' 因为 nums[25] == 2
    * 第二次转换后的字符串为: "cdeabab"
* 字符串最终长度: 字符串为 "cdeabab", 长度为 7 个字符. 
```

## 解法思路

### 矩阵乘法 + 快速幂

- 核心思想: 首先对s中出现的每个字符计数 根据 nums 数组生成每个字符转换后的状态转移矩阵 然后用矩阵乘法快速幂计算出 t 次转换后的字符串中每个字符的数量 最后将每个字符的数量相加即为最终结果
- 时间复杂度: O(26³ * log(t))
- 空间复杂度: O(26²)

```cpp
const int MOD = 1e9 + 7;
class Solution {
public:
    using Matrix = vector<vector<int>>;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> count(26, 0);
        for (char c : s)  {
            count[c - 'a']++;
        }
        Matrix M = buildMatrix(nums);
        Matrix mat = matrixPow(M, t);
        vector<long long> res(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) continue;
            for (int j = 0; j < 26; ++j) {
                res[j] = (res[j] + count[i] * mat[i][j]) % MOD;
            }
        }
        long long total = 0;
        for (long long x : res) {
            total = (total + x) % MOD;
        }
        return total;
    }
    Matrix buildMatrix(vector<int>& nums) {
        Matrix M(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < nums[i]; ++k) {
                int j = (i + 1 + k) % 26;
                M[i][j]++;
            }
        }
        return M;
    }
    Matrix matrixPow(Matrix base, int power) {
        Matrix res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) res[i][i] = 1;
        while (power > 0) {
            if (power & 1) res = multiply(res, base);
            base = multiply(base, base);
            power >>= 1;
        }
        return res;
    }
    Matrix multiply(Matrix& a, Matrix& b) {
        Matrix res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    res[i][j] = (res[i][j] + (long long)a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return res;
    }
};
```

## Tags

[哈希表](/tags/hash-table.md) | [数学](/tags/math.md) | [字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md) | [计数](/tags/counting.md)
