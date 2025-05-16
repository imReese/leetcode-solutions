// Link: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/
// Level: Medium
// Date: 2025-05-16

func getWordsInLongestSubsequence(words []string, groups []int) []string {
	isAdjacent := func(a, b string) bool {
		if len(a) != len(b) {
			return false
		}
		diff := 0
		for i := 0; i < len(a); i++ {
			if a[i] != b[i] {
				diff++
				if diff > 1 {
					return false
				}
			}
		}
		return diff == 1
	}

	n := len(words)
	dp := make([]int, n)
	prev := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = 1
		prev[i] = -1
	}
	maxLen := 1
	maxIdx := 0
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if groups[i] != groups[j] && isAdjacent(words[i], words[j]) {
				if dp[j]+1 > dp[i] {
					dp[i] = dp[j] + 1
					prev[i] = j
				}
			}
		}
		if dp[i] > maxLen {
			maxLen = dp[i]
			maxIdx = i
		} else if dp[i] == maxLen {
			maxIdx = i
		}
	}
	path := make([]int, 0)
	curr := maxIdx
	for curr != -1 {
		path = append(path, curr)
		curr = prev[curr]
	}
	for i, j := 0, len(path)-1; i < j; i, j = i+1, j-1 {
		path[i], path[j] = path[j], path[i]
	}
	res := make([]string, len(path))
	for i, idx := range path {
		res[i] = words[idx]
	}
	return res
}
