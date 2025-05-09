# Link: https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-ii/
# Level: Medium
# Date: 2025-05-09

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n, m = len(moveTime), len(moveTime[0])
        dist = [[float('inf')] * m for _ in range(n)]
        dist[0][0] = 0

        pq = []
        heapq.heappush(pq, (0, 0, 0))
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while pq:
            t, x, y = heapq.heappop(pq)
            if x == n - 1 and y == m - 1:
                return t
            if t > dist[x][y]:
                continue
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m:
                    cost = 1 + ((x ^ y) & 1)
                    nt = max(t, moveTime[nx][ny]) + cost
                    if nt < dist[nx][ny]:
                        dist[nx][ny] = nt
                        heapq.heappush(pq, (nt, nx, ny))
        return -1
