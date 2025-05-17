# Link: https://leetcode.cn/problems/top-k-frequent-elements/
# Level: Medium
# Date: 2025-05-17

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        return [item[0] for item in heapq.nlargest(k, cnt.items(), key=lambda x: x[1])]
