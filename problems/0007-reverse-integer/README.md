# 7. 整数翻转(Reverse Integer)

[LeetCode 原题链接](https://leetcode.cn/problems/reverse-integer/) | 难度: **中等** | 标签: `数学`

## 题目描述

给你一个 32 位的有符号整数 x , 返回将 x 中的数字部分反转后的结果.

如果反转后整数超过 32 位的有符号整数的范围 [−2³¹,  2³¹ − 1] , 就返回 0.

假设环境不允许存储 64 位整数(有符号或无符号).

示例:

```plaintext
输入: x = 123
输出: 321
```

## 解法思路

### 数学

- 核心思想: 逐步取x的末位数字, 添加至rev中, 直至x为0.
- 时间复杂度: O(log|x|)
- 空间复杂度: O(1)

```python
# solution.py
class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        rev = 0
        while x != 0:
            # INT_MIN 也是一个负数, 不能写成 rev < INT_MIN // 10
            if rev < INT_MIN // 10 + 1 or rev > INT_MAX // 10:
                return 0
            digit = x % 10
            # Python3 的取模运算在 x 为负数时也会返回 [0, 9) 以内的结果, 因此这里需要进行特殊判断
            if x < 0 and digit > 0:
                digit -= 10
            # 同理, Python3 的整数除法在 x 为负数时会向下（更小的负数）取整, 因此不能写成 x //= 10
            x = (x - digit) // 10
            rev = rev * 10 + digit
        return rev
```

### 关键点

- 数学问题, 注意边界条件.
- 题目不允许使用64位整数

## 相似题目

- [8. 字符串转换整数(atoi)](https://leetcode.cn/problems/string-to-integer-atoi/)
