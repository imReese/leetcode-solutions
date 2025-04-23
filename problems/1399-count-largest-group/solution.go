// Link: https://leetcode.cn/problems/count-largest-group/
// Level: Easy
// Date: 2025-04-23

func countLargestGroup(n int) int {
	mp := make(map[int]int)
	max_sum := 0
	for i := 1; i <= n; i++ {
		key := 0
		i0 := i
		for i0 > 0 {
			key += i0 % 10
			i0 /= 10
		}
		mp[key]++
		if mp[key] > max_sum {
			max_sum = mp[key]
		}
	}

	ans := 0
	for _, v := range mp {
		if v == max_sum {
			ans++
		}
	}
	return ans
}
