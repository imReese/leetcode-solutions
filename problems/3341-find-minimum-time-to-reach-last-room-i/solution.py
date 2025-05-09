# Link: https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-i/
# Level: Medium
# Date: 2025-05-09

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n, m = len(moveTime), len(moveTime[0])
        dist = [[float('inf')] * m for _ in range(n)]
        dist[0][0] = moveTime[0][0]
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        q = []
        heapq.heappush(q, (0, 0, 0))

        while q:
            t, x, y = heapq.heappop(q)
            if x == n - 1 and y == m - 1:
                return t
            if t > dist[x][y]:
                continue

            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m:
                    nt = max(t, moveTime[nx][ny]) + 1
                    if nt < dist[nx][ny]:
                        dist[nx][ny] = nt
                        heapq.heappush(q, (nt, nx, ny))
        return -1
