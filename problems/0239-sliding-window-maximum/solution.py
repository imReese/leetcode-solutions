# Link: https://leetcode.cn/problems/sliding-window-maximum/
# Level: Hard
# Date: 2025-05-16

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        res = []

        for i, num in enumerate(nums):
            if dq and dq[0] == i - k:
                dq.popleft()
            while dq and nums[dq[-1]] <= num:
                dq.pop()

            dq.append(i)

            if i >= k - 1:
                res.append(nums[dq[0]])
        return res
