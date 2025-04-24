# Link: https://leetcode.cn/problems/valid-phone-numbers/
# Level: Easy
# Date: 2025-04-24

# Read from the file file.txt and output all valid phone numbers to stdout.
#!/bin/bash
grep -E '^(\([0-9]{3}\) [0-9]{3}-[0-9]{4}|[0-9]{3}-[0-9]{3}-[0-9]{4})$' file.txt