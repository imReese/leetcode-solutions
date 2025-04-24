# Link: https://leetcode.cn/problems/count-complete-subarrays-in-an-array/
# Level: Medium 
# Date: 2025-04-24

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        distinct = len(set(nums))
        cnt = {}
        right = 0
        for left in range(n):
            if left > 0:
                remove = nums[left - 1]
                cnt[remove] -= 1
                if cnt[remove] == 0:
                    cnt.pop(remove)
            while right < n and len(cnt) < distinct:
                add = nums[right]
                cnt[add] = cnt.get(add, 0) + 1
                right += 1
            if len(cnt) == distinct:
                res += n - right + 1
        return res
