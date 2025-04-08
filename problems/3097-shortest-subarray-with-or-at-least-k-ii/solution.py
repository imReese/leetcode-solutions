# Link: https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/
# Level: Medium
# Date: 2025-04-08

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        bits = [0] * 30
        res = inf

        def calc(bits):
            return sum(1 << i for i in range(30) if bits[i] > 0)

        left = 0
        for right in range(n):
            for i in range(30):
                bits[i] += (nums[right] >> i) & 1
            while left <= right and calc(bits) >= k:
                res = min(res, right - left + 1)
                for i in range(30):
                    bits[i] -= (nums[left] >> i) & 1
                left += 1

        return -1 if res == inf else res