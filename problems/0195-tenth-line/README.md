# 195. 第十行 (Tenth Line)

[LeetCode 原题链接](https://leetcode.cn/problems/transpose-file/) | 难度: **简单** | 标签: `Shell`

## 题目描述

给定一个文本文件 file.txt, 请只打印这个文件中的第十行.

示例:

```plaintext
假设 file.txt 有如下内容:
    Line 1
    Line 2
    Line 3
    Line 4
    Line 5
    Line 6
    Line 7
    Line 8
    Line 9
    Line 10
你的脚本应当显示第十行:
    Line 10
```

## 解法思路

```bash
#!/bin/bash
sed -n '10p' file.txt
```
