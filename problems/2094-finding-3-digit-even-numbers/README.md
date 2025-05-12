# 2094. 找出 3 位偶数 (Finding 3-Digit Even Numbers)

[LeetCode 原题链接](https://leetcode.cn/problems/finding-3-digit-even-numbers/) | 难度: **简单** | 标签: `数组`、`哈希表`、`枚举`、`排序`

## 题目描述

给你一个整数数组 `digits`, 其中每个元素是一个数字(`0 - 9`). 数组中可能存在重复元素.

你需要找出 **所有** 满足下述条件且 **互不相同** 的整数:

- 该整数由 `digits` 中的三个元素按 **任意** 顺序 **依次连接** 组成.
- 该整数不含 **前导零**
- 该整数是一个 **偶数**

例如, 给定的 `digits` 是 `[1, 2, 3]`, 整数 `132` 和 `312` 满足上面列出的全部条件.

将找出的所有互不相同的整数按 **递增顺序** 排列, 并以数组形式返回.

示例:

```plaintext
输入: digits = [2,1,3,0]
输出: [102,120,130,132,210,230,302,310,312,320]
解释:
    所有满足题目条件的整数都在输出数组中列出. 
    注意，答案数组中不含有 奇数 或带 前导零 的整数.
```

## 解法思路

### 三重遍历

- 时间复杂度: O(n³)
- 空间复杂度: O(k) k 为答案数组长度

```cpp
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        if (n < 3) {
            return {};
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j || digits[k] % 2 != 0) {
                        continue;
                    }
                    s.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        vector<int> res(s.begin(), s.end());
        sort(res.begin(), res.end());
        return res;
    }
};
```

## 相似题目

- [1295. 统计位数为偶数的数字](https://leetcode.cn/problems/find-numbers-with-even-number-of-digits/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [枚举](/tags/enumeration.md) | [排序](/tags/sorting.md)
