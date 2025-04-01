# LCR 133. 位 1 的个数 (位 1 的个数)

[LeetCode 原题链接](https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/) | 难度: **简单** | 标签: `位运算`

## 题目描述

编写一个函数, 输入是一个无符号整数(以二进制串的形式), 返回其二进制表达式中数字位数为 '1' 的个数(也被称为 [汉明重量](http://en.wikipedia.org/wiki/Hamming_weight)).

提示:

- 请注意, 在某些语言(如 Java)中, 没有无符号整数类型. 在这种情况下, 输入和输出都将被指定为有符号整数类型, 并且不应影响您的实现, 因为无论整数是有符号的还是无符号的, 其内部的二进制表示形式都是相同的.
- 在 Java 中, 编译器使用 [二进制补码](https://baike.baidu.com/item/二进制补码/5295284) 记法来表示有符号整数.

示例:

```plaintext
输入: n = 11 (控制台输入 00000000000000000000000000001011)
输出: 3
解释: 输入的二进制串 **00000000000000000000000000001011** 中, 共有三位为 '1'.
```

## 解法思路

### 位运算

- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int cnt = 0;
            while(n) {
                cnt += n&1;
                n >>= 1;
            }
            return cnt;
        }
};
```

## Tags
[位运算](/tags/bit-manipulation.md)
