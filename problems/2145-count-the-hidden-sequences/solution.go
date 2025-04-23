// Link: https://leetcode.cn/problems/count-the-hidden-sequences/
// Level: Medium
// Date: 2025-04-21

func numberOfArrays(differences []int, lower int, upper int) int {
	num := int(0)
	min_num := int(0)
	max_num := int(0)
	for _, d := range differences {
		num += d
		min_num = min(min_num, num)
		max_num = max(max_num, num)
		if max_num-min_num > upper-lower {
			return 0
		}
	}
	res := int((upper - lower) - (max_num - min_num) + 1)
	return res
}
