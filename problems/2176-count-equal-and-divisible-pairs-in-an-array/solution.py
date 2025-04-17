# Link: https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/
# Level: Medium
# Date: 2025-04-17

class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] == nums[j] and (i * j) % k == 0:
                    cnt += 1
        return cnt
