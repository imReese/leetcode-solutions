# Link: https://leetcode.cn/problems/word-frequency/
# Level: Medium
# Date: 2025-04-24

# Read from the file words.txt and output the word frequency list to stdout.
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
