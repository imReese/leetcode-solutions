// Link: https://leetcode.cn/problems/longest-consecutive-sequence/
// Level: Medium
// Date: 2025-05-10

func longestConsecutive(nums []int) int {
	numMap := make(map[int]bool)
	for _, num := range nums {
		numMap[num] = true
	}
	maxLen := 0
	for num := range numMap {
		if !numMap[num-1] {
			currNum := num
			currLen := 1
			for numMap[currNum+1] {
				currNum++
				currLen++
			}
			if currLen > maxLen {
				maxLen = currLen
			}
		}
	}
	return maxLen
}
