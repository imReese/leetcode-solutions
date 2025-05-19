// Link: https://leetcode.cn/problems/type-of-triangle/
// Level: Easy
// Date: 2025-05-19

func triangleType(nums []int) string {
	sort.Ints(nums)
	if nums[0]+nums[1] <= nums[2] {
		return "none"
	} else if nums[0] == nums[2] {
		return "equilateral"
	} else if nums[0] == nums[1] || nums[1] == nums[2] {
		return "isosceles"
	} else {
		return "scalene"
	}
}
