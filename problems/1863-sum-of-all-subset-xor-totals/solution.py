# Link: https://leetcode.cn/problems/sum-of-all-subset-xor-totals/
# Level: Easy
# Date: 2025-04-06

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for num in nums:
            res = res | num;
        return (res << (n - 1));