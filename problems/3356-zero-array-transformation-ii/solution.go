// Link: https://leetcode.cn/problems/zero-array-transformation-ii/
// Level: Medium
// Date: 2025-05-21

func minZeroArray(nums []int, queries [][]int) int {
	m := len(queries)
	left, right := -1, m+1
	for left+1 < right {
		mid := (left + right) / 2
		if check(nums, queries, mid) {
			right = mid
		} else {
			left = mid
		}
	}
	if right <= m {
		return right
	} else {
		return -1
	}
}

func check(nums []int, queries [][]int, k int) bool {
	n := len(nums)
	pre := make([]int, n+2)
	for i := 0; i < k; i++ {
		l, r, val := queries[i][0], queries[i][1], queries[i][2]
		pre[l] -= val
		if r+1 < n {
			pre[r+1] += val
		}
	}

	prefixSum := 0
	for i := 0; i < n; i++ {
		prefixSum += pre[i]
		if nums[i]+prefixSum > 0 {
			return false
		}
	}
	return true
}
