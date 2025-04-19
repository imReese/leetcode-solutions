# Link: https://leetcode.cn/problems/count-of-range-sum/
# Level: Hard
# Date: 2025-04-19

class FenwickTree:
    def __init__(self, size):
        self.n = size
        self.tree = [0] * (size + 1)

    def update(self, index, delta):
        while index <= self.n:
            self.tree[index] += delta
            index += index & -index

    def query(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index -= index & -index
        return result

class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        pre_sum = [0]
        s = 0
        for num in nums:
            s += num
            pre_sum.append(s)

        all_numbers = set()
        for s_val in pre_sum:
            all_numbers.add(s_val)
            all_numbers.add(s_val - lower)
            all_numbers.add(s_val - upper)

        sorted_all = sorted(all_numbers)
        value_to_idx = {v : i + 1 for i, v in enumerate(sorted_all)}

        ft = FenwickTree(len(sorted_all))
        res = 0
        for s_val in pre_sum:
            cur_left = s_val - upper
            cur_right = s_val - lower

            left_idx = value_to_idx[cur_left]
            right_idx = value_to_idx[cur_right]

            res += ft.query(right_idx) - ft.query(left_idx - 1)
            s_pos = value_to_idx[s_val]
            ft.update(s_pos, 1)

        return res
