// Link: https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-i/
// Level: Medium
// Date: 2025-05-09

type node struct {
	t, x, y int
}

type PriorityQueue []*node

func (pq PriorityQueue) Len() int {
	return len(pq)
}
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].t < pq[j].t
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*node)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func minTimeToReach(moveTime [][]int) int {
	n, m := len(moveTime), len(moveTime[0])
	dirs := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	dist := make([][]int, n)
	for i := range dist {
		dist[i] = make([]int, m)
		for j := range dist[i] {
			dist[i][j] = 1<<31 - 1
		}
	}
	dist[0][0] = 0
	q := &PriorityQueue{}
	heap.Init(q)
	heap.Push(q, &node{0, 0, 0})

	for q.Len() > 0 {
		curr := heap.Pop(q).(*node)
		if curr.x == n-1 && curr.y == m-1 {
			return curr.t
		}
		if curr.t > dist[curr.x][curr.y] {
			continue
		}
		for _, d := range dirs {
			nx, ny := curr.x+d[0], curr.y+d[1]
			if nx >= 0 && nx < n && ny >= 0 && ny < m {
				nt := max(curr.t, moveTime[nx][ny]) + 1
				if nt < dist[nx][ny] {
					dist[nx][ny] = nt
					heap.Push(q, &node{nt, nx, ny})
				}
			}
		}
	}
	return -1
}
