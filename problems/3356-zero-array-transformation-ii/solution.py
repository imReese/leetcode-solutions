# Link: https://leetcode.cn/problems/zero-array-transformation-ii/
# Level: Medium
# Date: 2025-05-21

class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n, m = len(nums), len(queries)
        left, right = -1, m+1
        while left + 1 < right:
            mid = (left + right) // 2
            if self.check(nums, queries, mid):
                right = mid
            else:
                left = mid
        return right if right <= m else -1

    def check(self, nums: List[int], queries: List[List[int]], k: int) -> bool:
        n = len(nums)
        pre = [0] * (n + 2)

        for i in range(k):
            l, r, val = queries[i]
            pre[l] -= val
            if r + 1 < n:
                pre[r + 1] += val

        prefix_sum = 0
        for i in range(n):
            prefix_sum += pre[i]
            if nums[i] + prefix_sum > 0:
                return False
        return True
