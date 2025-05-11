// Link: https://leetcode.cn/problems/three-consecutive-odds/
// Level: Easy
// Date: 2025-05-11

func threeConsecutiveOdds(arr []int) bool {
	n := len(arr)
	for i := 0; i <= n-3; i++ {
		if (arr[i]&1) == 1 && (arr[i+1]&1) == 1 && (arr[i+2]&1) == 1 {
			return true
		}
	}
	return false
}
