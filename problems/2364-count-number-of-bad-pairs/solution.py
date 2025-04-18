# Link: https://leetcode.cn/problems/count-number-of-bad-pairs/
# Level: Medium
# Date: 2025-04-18

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = Counter()
        ans = 0
        for i, num in enumerate(nums):
            ans += i - cnt[num - i]
            cnt[num - i] += 1
        return ans
