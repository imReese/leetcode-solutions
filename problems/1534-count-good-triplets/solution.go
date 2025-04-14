// Link: https://leetcode.cn/problems/count-good-triplets/
// Level: Easy
// Date: 2025-04-14

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func countGoodTriplets(arr []int, a int, b int, c int) int {
    n := len(arr)
	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				if abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c {
					ans++
				}
			}
		}
	}
	return ans
}
