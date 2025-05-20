// Link: https://leetcode.cn/problems/zero-array-transformation-i/
// Level: Medium
// Date: 2025-05-20

func isZeroArray(nums []int, queries [][]int) bool {
	n := len(nums)
	diff := make([]int, n+2)
	for _, q := range queries {
		l, r := q[0], q[1]
		diff[l]++
		if r+1 <= n {
			diff[r+1]--
		}
	}

	prefix := 0
	for i := 0; i < n; i++ {
		prefix += diff[i]
		if nums[i] < 0 || prefix < nums[i] {
			return false
		}
	}
	return true
}
