// Link: https://leetcode.cn/problems/count-the-number-of-fair-pairs/
// Level: Medium
// Date: 2025-04-19

func countFairPairs(nums []int, lower int, upper int) int64 {
	slices.Sort(nums)
	res := int64(0)
	for j, x := range nums {
		r := sort.SearchInts(nums[:j], upper-x+1)
		l := sort.SearchInts(nums[:j], lower-x)
		res += int64(r - l)
	}
	return res
}
