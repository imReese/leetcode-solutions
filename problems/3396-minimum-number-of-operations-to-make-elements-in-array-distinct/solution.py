# Link: https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
# Level: Easy
# Date: 2025-04-08

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        s = set()
        for i in range(n - 1, -1, -1):
            if nums[i] in s:
                res = i // 3 + 1
                break
            else:
                s.add(nums[i])
        return res