// Link: https://leetcode.cn/problems/target-sum/
// Level: Medium
// Date: 2025-05-19

func findTargetSumWays(nums []int, target int) int {
	n := len(nums)
	var backtrack func(int, int)
	backtrack = func(index, currSum int) int {
		if index == n {
			if currSum == target {
				return 1
			}
			return 0
		}
		return backtrack(index+1, currSum+nums[index]) + backtrack(index+1, currSum-nums[index])
	}
	res := backtrack(0, 0)
	return res
}
