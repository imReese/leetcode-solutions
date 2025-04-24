# 192. 统计词频 (Word Frequency)

[LeetCode 原题链接](https://leetcode.cn/problems/word-frequency/) | 难度: **中等** | 标签: `Shell`

## 题目描述

写一个 bash 脚本以统计一个文本文件 words.txt 中每个单词出现的频率.

为了简单起见, 你可以假设:

- words.txt只包括小写字母和 ' '.
- 每个单词只由小写字母组成.
- 单词间由一个或多个空格字符分隔.

示例:

```plaintext
假设 words.txt 内容如下:
    the day is sunny the the
    the sunny is is
你的脚本应当输出(以词频降序排列):
    the 4
    is 3
    sunny 2
    day 1
```

## 解法思路

```bash
#!/bin/bash

# 将连续的空格转换为换行符，分割单词，并过滤空行
tr -s ' ' '\n' < words.txt | grep -v '^$' |
# 排序以便统计
sort |
# 统计每个单词的出现次数
uniq -c |
# 按次数降序排序，次数相同则按单词升序
sort -k1,1nr -k2,2 |
# 调整输出格式为“单词 次数”
awk '{print $2, $1}'
```
