# Link: https://leetcode.cn/problems/maximum-building-height/
# Level: Hard
# Date: 2025-04-09

class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        r = restrictions
        r.append([1, 0])
        r.sort()
        if r[-1][0] != n:
            r.append([n, n - 1])
        
        m = len(r)
        for i in range(1, m):
            r[i][1] = min(r[i][1], r[i-1][1] + (r[i][0] - r[i-1][0]))

        for j in range(m - 2, 0, -1):
            r[j][1] = min(r[j][1], r[j+1][1] + (r[j+1][0] - r[j][0]))
        
        res = 0
        for i in range(m-1):
            best = ((r[i+1][0] - r[i][0]) + r[i][1] + r[i+1][1]) // 2
            res = max(res, best)
        return res

