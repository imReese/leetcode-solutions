# Link: https://leetcode.cn/problems/transpose-file/
# Level: Medium
# Date: 2025-04-23

# Read from the file file.txt and print its transposed content to stdout.
#!/bin/bash
awk '{for(i=1;i<=NF;i++)a[i]=a[i]?a[i]" "$i:$i}END{for(i=1;i<=NF;i++)print a[i]}' file.txt