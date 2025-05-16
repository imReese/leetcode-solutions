// Link: https://leetcode.cn/problems/sliding-window-maximum/
// Level: Hard
// Date: 2025-05-16

package main

func maxSlidingWindow(nums []int, k int) []int {
	var q []int
	var res []int
	for i, num := range nums {
		if len(q) > 0 && q[0] == i-k {
			q = q[1:]
		}
		for len(q) > 0 && nums[q[len(q)-1]] < num {
			q = q[:len(q)-1]
		}
		q = append(q, i)
		if i >= k-1 {
			res = append(res, nums[q[0]])
		}
	}
	return res
}
