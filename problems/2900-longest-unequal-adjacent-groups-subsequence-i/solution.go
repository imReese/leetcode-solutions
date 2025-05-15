// Link: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/
// Level: Easy
// Date: 2025-05-15

func getLongestSubsequence(words []string, groups []int) []string {
	n := len(words)
	if n == 0 {
		return []string{}
	}

	var len0, len1 int
	path0, path1 := make([]int, 0), make([]int, 0)
	if groups[0] == 0 {
		len0 = 1
		path0 = append(path0, 0)
	} else {
		len1 = 1
		path1 = append(path1, 0)
	}

	for i := 1; i < n; i++ {
		if groups[i] == 0 {
			newPath := make([]int, len(path0))
			copy(newPath, path0)
			newLen := len0

			if len1+1 > newLen {
				newPath = append(append([]int{}, path1...), i)
				newLen = len1 + 1
			}
			if newLen > len0 {
				len0 = newLen
				path0 = newPath
			}
		} else {
			newPath := make([]int, len(path1))
			copy(newPath, path1)
			newLen := len1

			if len0+1 > newLen {
				newPath = append(append([]int{}, path0...), i)
				newLen = len0 + 1
			}
			if newLen > len1 {
				len1 = newLen
				path1 = newPath
			}
		}
	}

	var res []string
	if len0 > len1 {
		for _, idx := range path0 {
			res = append(res, words[idx])
		}
	} else {
		for _, idx := range path1 {
			res = append(res, words[idx])
		}
	}
	return res
}
