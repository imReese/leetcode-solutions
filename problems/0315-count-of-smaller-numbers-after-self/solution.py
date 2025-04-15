# Link: https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
# Level: Hard
# Date: 2025-04-15

class FenwickTree:
    def __init__(self, size):
        self.n = size
        self.tree = [0] * (self.n + 1)

    def update(self, index, delta):
        while index <= self.n:
            self.tree[index] += delta
            index += index & -index
        
    def query(self, index):
        res = 0
        while index > 0:
            res += self.tree[index]
            index -= index & -index
        return res

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        sorted_num = sorted(nums)
        unique = []
        prev = None
        for num in sorted_num:
            if num != prev:
                unique.append(num)
                prev = num
        
        m = len(unique)
        ft = FenwickTree(m)
        counts = [0] * len(nums)
        for i in range(len(nums) - 1, -1, -1):
            x = nums[i]
            index = bisect.bisect_left(unique, x) + 1
            count = ft.query(index - 1)
            counts[i] = count
            ft.update(index, 1)
        return counts
