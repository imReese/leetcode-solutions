// Link: https://leetcode.cn/problems/finding-3-digit-even-numbers/
// Level: Easy
// Date: 2025-05-12

func findEvenNumbers(digits []int) []int {
	n := len(digits)
	if n < 3 {
		return []int{}
	}
	m := make(map[int]bool)
	for i := 0; i < n; i++ {
		if digits[i] == 0 {
			continue
		}
		for j := 0; j < n; j++ {
			if j == i {
				continue
			}
			for k := 0; k < n; k++ {
				if k == i || k == j || digits[k]%2 != 0 {
					continue
				}
				num := digits[i]*100 + digits[j]*10 + digits[k]
				m[num] = true
			}
		}
	}
	res := make([]int, 0, len(m))
	for num := range m {
		res = append(res, num)
	}
	sort.Ints(res)
	return res
}
