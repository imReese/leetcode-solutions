# Link: https://leetcode.cn/problems/maximal-rectangle/
# Level: Hard
# Date: 2025-04-12

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        res = 0

        left = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == "1":
                    left[i][j] = (0 if j == 0 else left[i][j - 1]) + 1

        for j in range(n):
            up = [0 for _ in range(m)]
            down = [0 for _ in range(m)]
            stk = list()
            for i in range(m):
                while stk and left[stk[-1]][j] >= left[i][j]:
                    stk.pop()
                up[i] = (-1 if not stk else stk[-1])
                stk.append(i)
            stk.clear()
            for i in range(m-1, -1, -1):
                while stk and left[stk[-1]][j] >= left[i][j]:
                    stk.pop()
                down[i] = (m if not stk else stk[-1])
                stk.append(i)
            for i in range(m):
                height = down[i] - up[i] - 1
                area = height * left[i][j]
                res = max(res, area)

        return res
