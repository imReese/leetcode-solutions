# 194. 转置文件 (Transpose File)

[LeetCode 原题链接](https://leetcode.cn/problems/transpose-file/) | 难度: **中等** | 标签: `Shell`

## 题目描述

给定一个文件 file.txt, 转置它的内容.

你可以假设每行列数相同, 并且每个字段由 ' ' 分隔.

示例:

```plaintext
假设 file.txt 文件内容如下:
    name age
    alice 21
    ryan 30
应当输出:
    name alice ryan
    age 21 30
```

## 解法思路

```bash
#!/bin/bash
awk '{for(i=1;i<=NF;i++)a[i]=a[i]?a[i]" "$i:$i}END{for(i=1;i<=NF;i++)print a[i]}' file.txt
```
