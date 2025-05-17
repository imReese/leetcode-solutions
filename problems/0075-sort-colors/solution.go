// Link: https://leetcode.cn/problems/sort-colors/
// Level: Medium
// Date: 2025-05-17

func sortColors(nums []int) {
	p0, p1 := 0, 0
	for i, num := range nums {
		if num == 1 {
			nums[i], nums[p1] = nums[p1], nums[i]
			p1++
		} else if num == 0 {
			nums[i], nums[p0] = nums[p0], nums[i]
			if p0 < p1 {
				nums[i], nums[p1] = nums[p1], nums[i]
			}
			p0++
			p1++
		}
	}
}
