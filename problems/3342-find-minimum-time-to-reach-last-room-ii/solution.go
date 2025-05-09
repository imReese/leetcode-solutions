// Link: https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-ii/
// Level: Medium
// Date: 2025-05-09

type Node struct {
	t, x, y int
}

type PriorityQueue []*Node

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
	item := x.(*Node)
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
	dist := make([][]int, n)
	for i := range dist {
		dist[i] = make([]int, m)
		for j := range dist[i] {
			dist[i][j] = 1<<31 - 1
		}
	}
	dist[0][0] = 0

	pq := &PriorityQueue{}
	heap.Init(pq)
	heap.Push(pq, &Node{0, 0, 0})
	dirs := [4][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for pq.Len() > 0 {
		node := heap.Pop(pq).(*Node)
		t, x, y := node.t, node.x, node.y
		if x == n-1 && y == m-1 {
			return t
		}
		if t > dist[x][y] {
			continue
		}
		for _, d := range dirs {
			nx, ny := x+d[0], y+d[1]
			if nx >= 0 && nx < n && ny >= 0 && ny < m {
				cost := 1 + ((x ^ y) & 1)
				nt := max(t, moveTime[nx][ny]) + cost
				if nt < dist[nx][ny] {
					dist[nx][ny] = nt
					heap.Push(pq, &Node{nt, nx, ny})
				}
			}
		}
	}
	return -1
}
