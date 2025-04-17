# Link: https://leetcode.cn/problems/median-of-two-sorted-arrays/
# Level: Hard
# Date: 2025-04-17

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def getKthElement(k):
            index1, index2 = 0, 0
            while True:
                if index1 == m:
                    return nums2[index2 + k - 1]
                if index2 == n:
                    return nums1[index1 + k - 1]
                if k == 1:
                    return min(nums1[index1], nums2[index2])
                
                new_index1 = min(index1 + k // 2 - 1, m - 1)
                new_index2 = min(index2 + k // 2 - 1, n - 1)
                pivot1, pivot2 = nums1[new_index1], nums2[new_index2]
                if pivot1 <= pivot2:
                    k -= new_index1 - index1 + 1
                    index1 = new_index1 + 1
                else:
                    k -= new_index2 - index2 + 1
                    index2 = new_index2 + 1

        m, n = len(nums1), len(nums2)
        total_len = m + n
        if total_len % 2 == 1:
            return getKthElement((total_len + 1) // 2)
        else:
            return (getKthElement(total_len // 2) + getKthElement(total_len // 2 + 1)) / 2
