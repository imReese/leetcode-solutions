# Link: https://leetcode.cn/problems/count-the-number-of-good-subarrays/
# Level: Medium
# Date: 2025-04-16

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        same = 0
        cnt = Counter()
        ans = 0
        right = -1
        for left in range(n):
            while same < k and right + 1 < n:
                right += 1
                same += cnt[nums[right]]
                cnt[nums[right]] += 1
            if same >= k:
                ans += n - right
            cnt[nums[left]] -= 1
            same -= cnt[nums[left]]

        return ans