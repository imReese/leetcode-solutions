# Link: https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
# Level: Medium
# Date: 2025-05-10

class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1, sum2 = sum(nums1), sum(nums2)
        zero1, zero2 = 0, 0
        for num in nums1:
            if num == 0:
                zero1 += 1
        for num in nums2:
            if num == 0:
                zero2 += 1
        s1 = sum1 + zero1
        s2 = sum2 + zero2
        if zero1 == 0 and zero2 == 0:
            return sum1 if sum1 == sum2 else -1
        elif zero1 == 0:
            return sum1 if sum1 >= s2 else -1
        elif zero2 == 0:
            return sum2 if sum2 >= s1 else -1
        else:
            return max(s1, s2)
