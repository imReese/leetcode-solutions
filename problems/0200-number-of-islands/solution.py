# Link: https://leetcode.cn/problems/number-of-islands/
# Level: Medium
# Date: 2025-05-13

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        rows, cols = len(grid), len(grid[0])

        cnt = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    cnt += 1
                    queue = deque([(i, j)])
                    grid[i][j] = "0"
                    while queue:
                        x, y = queue.popleft()
                        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == "1":
                                grid[nx][ny] = "0"
                                queue.append((nx, ny))
        return cnt
