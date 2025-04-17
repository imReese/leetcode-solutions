// Link: https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/
// Level: Medium
// Date: 2025-04-17

func countPairs(nums []int, k int) int {
	n := len(nums)
	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if nums[i] == nums[j] && (i*j)%k == 0 {
				ans++
			}
		}
	}
	return ans
}
