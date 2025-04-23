# Link: https://leetcode.cn/problems/count-the-hidden-sequences/
# Level: Medium
# Date: 2025-04-21

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        num = 0
        min_num = 0
        max_num = 0
        for d in differences:
            num += d
            min_num = min(min_num, num)
            max_num = max(max_num, num)
            if max_num - min_num > upper - lower:
                return 0
        return (upper - lower) - (max_num - min_num) + 1
