// Link: https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/
// Level: Medium
// Date: 2025-05-13

const MOD = 1_000_000_007

func lengthAfterTransformations(s string, t int) int {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}

	prev := make([]int, 26)
	for i := range prev {
		prev[i] = 1
	}

	for k := 0; k < t; k++ {
		curr := make([]int, 26)
		for c := 0; c < 26; c++ {
			if c != 25 {
				curr[c] = prev[c+1] % MOD
			} else {
				curr[c] = (prev[0] + prev[1]) % MOD
			}
		}
		prev = curr
	}
	res := 0
	for i := 0; i < 26; i++ {
		res = (res + cnt[i]*prev[i]) % MOD
	}
	return res
}
