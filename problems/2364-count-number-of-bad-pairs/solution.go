// Link: https://leetcode.cn/problems/count-number-of-bad-pairs/
// Level: Medium
// Date: 2025-04-18

func countBadPairs(nums []int) int64 {
	mp := make(map[int]int)
	ans := int64(0)
	for i, num := range nums {
		ans += int64(i - mp[num-i])
		mp[num-i]++
	}
	return ans
}
