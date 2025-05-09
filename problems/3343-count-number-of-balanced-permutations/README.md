# 3343. 统计平衡排列的数目 (Count Number of Balanced Permutations)

[LeetCode 原题链接](https://leetcode.cn/problems/count-number-of-balanced-permutations/) | 难度: **困难** | 标签: `数学`、`字符串`、`动态规划`、`组合数学`

## 题目描述

给你一个字符串 `num`. 如果一个数字字符串的奇数位下标的数字之和与偶数位下标的数字之和相等, 那么我们称这个数字字符串是 **平衡的**.

请你返回 `num` **不同排列** 中, **平衡** 字符串的数目.

由于答案可能很大, 请你将答案对 `109 + 7` **取余** 后返回.

一个字符串的 **排列** 指的是将字符串中的字符打乱顺序后连接得到的字符串.

示例:

```plaintext
输入: num = "123"

输出: 2

解释:
- `num` 的不同排列包括: `"123"`, `"132"`, `"213"`, `"231"`, `"312"` 和 `"321"`.
- 它们之中, `"132"` 和 `"231"` 是平衡的. 所以答案为 2 。
```

## 解法思路

### 动态规划

- 核心思想:
  - 用 `dp[curr][oddCnt]` 表示当前数字和为 `curr`, 奇数位数字个数为 `oddCnt` 的方案数
  - 枚举 `num` 中所有数字, 从大到小枚举 `curr`, 从大到小枚举 `oddCnt`, 从大到小枚举 `cnt[i]` (当前数字 `i` 的个数), 累加 `dp[curr - i * cnt[i]][oddCnt - cnt[i]] * comb(oddCnt, cnt[i]) * comb(evenCnt, cnt[i])`
  - 其中 `comb(x, y)` 表示从 `x` 个数字中选出 `y` 个数字的方案数
- 时间复杂度: O(n²S) n为num长度, S为num的数字和的一半
- 空间复杂度: O(n² + nS)

```cpp
const long long MOD = 1e9 + 7;
class Solution {
public:
    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10, 0);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }
        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1));
        vector<vector<long long>> dp(target + 1, vector<long long>(maxOdd + 1));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
            }
        }
        dp[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i < 10; i++) {
            psum += cnt[i];
            totSum += i * cnt[i];
            for (int oddCnt = min(psum, maxOdd); oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--) {
                int evenCnt = psum - oddCnt;
                for (int curr = min(totSum, target); curr >= max(0, totSum - target); curr--) {
                    long long res = 0;
                    for (int j = max(0, cnt[i] - evenCnt); j <= min(cnt[i], oddCnt) && i * j <= curr; j++) {
                        long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                        res = (res + ways * dp[curr - i * j][oddCnt - j] % MOD) % MOD;
                    }
                    dp[curr][oddCnt] = res % MOD;
                }
            }
        }
        return dp[target][maxOdd];
    }
};
```

## Tags

[数学](/tags/math.md) | [字符串](/tags/string.md) | [动态规划](/tags/dynamic-programming.md) | [组合数学](/tags/combinatorics.md)
