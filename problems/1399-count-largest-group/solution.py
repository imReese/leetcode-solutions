# Link: https://leetcode.cn/problems/count-largest-group/
# Level: Easy
# Date: 2025-04-23

class Solution:
    def countLargestGroup(self, n: int) -> int:
        mp = collections.Counter()
        for i in range(1, n + 1):
            key = sum([int(x) for x in str(i)])
            mp[key] += 1
        max_sum = max(mp.values())
        ans = sum(1 for value in mp.values() if value == max_sum)
        return ans
