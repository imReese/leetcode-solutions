# 2521. 数组乘积中的不同质因数数目 (Distinct Prime Factors of Product of Array)

[LeetCode 原题链接](https://leetcode-cn.com/problems/distinct-prime-factors-of-product-of-array/) | 难度: **中等** | 标签: `数组`、`哈希表`、`数学`、`数论`

## 题目描述

给你一个正整数数组 `nums` ，对 `nums` 所有元素求积之后，找出并返回乘积中 **不同质因数** 的数目。

**注意：**

  * **质数** 是指大于 `1` 且仅能被 `1` 及自身整除的数字。
  * 如果 `val2 / val1` 是一个整数，则整数 `val1` 是另一个整数 `val2` 的一个因数。

 

**示例 1：**
[code] 
    **输入：** nums = [2,4,3,7,10,6]
    **输出：** 4
    **解释：**
    nums 中所有元素的乘积是：2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7 。
    共有 4 个不同的质因数，所以返回 4 。
    
[/code]

**示例 2：**
[code] 
    **输入：** nums = [2,4,8,16]
    **输出：** 1
    **解释：**
    nums 中所有元素的乘积是：2 * 4 * 8 * 16 = 1024 = 210 。
    共有 1 个不同的质因数，所以返回 1 。
[/code]

 

**提示：**

  * `1 <= nums.length <= 104`
  * `2 <= nums[i] <= 1000`

## 解法思路

```cpp
class Solution {
    public:
        int distinctPrimeFactors(vector<int>& nums) {
            unordered_set<int> primeFactors;
            for (int num : nums) {
                for (int i = 2; i * i <= num; ++i) {
                    if (num % i == 0) {
                        primeFactors.insert(i);
                        while (num % i == 0) {
                            num /= i;
                        }
                    }
                }
                if (num > 1) {
                    primeFactors.insert(num);
                }
            }
            return primeFactors.size();
        }
};
```
