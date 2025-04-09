# Link: https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/
# Level: Easy
# Date: 2025-04-09

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        if min(nums) < k:
            return -1
        s = set()
        for num in nums:
            if num > k:
                s.add(num)
        return len(s)