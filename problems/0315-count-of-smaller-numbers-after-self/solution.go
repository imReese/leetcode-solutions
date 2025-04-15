// Link: https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
// Level: Hard
// Date: 2025-04-15

type FenwickTree struct {
	tree []int
	n    int
}

func NewFenwickTree(size int) *FenwickTree {
	return &FenwickTree{
		tree: make([]int, size+1),
		n:    size,
	}
}

func (ft *FenwickTree) Update(index int, delta int) {
	for index <= ft.n {
		ft.tree[index] += delta
		index += index & -index
	}
}

func (ft *FenwickTree) Query(index int) int {
	sum := 0
	for index > 0 {
		sum += ft.tree[index]
		index -= index & -index
	}
	return sum
}

func countSmaller(nums []int) []int {
	if len(nums) == 0 {
		return []int{}
	}

	sorted := make([]int, len(nums))
	copy(sorted, nums)
	sort.Ints(sorted)

	unique := []int{sorted[0]}
	prev := sorted[0]
	for i := 1; i < len(sorted); i++ {
		if sorted[i] != prev {
			unique = append(unique, sorted[i])
			prev = sorted[i]
		}
	}
	m := len(unique)
	ft := NewFenwickTree(m)
	res := make([]int, len(nums))
	for i := len(nums) - 1; i >= 0; i-- {
		x := nums[i]
		index := sort.Search(len(unique), func(j int) bool {
			return unique[j] >= x
		}) + 1
		count := ft.Query(index - 1)
		res[i] = count
		ft.Update(index, 1)
	}
	return res
}
