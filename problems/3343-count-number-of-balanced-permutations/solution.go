// Link: https://leetcode.cn/problems/count-number-of-balanced-permutations/
// Level: Hard
// Date: 2025-05-09

const MOD = 1_000_000_007

func countBalancedPermutations(num string) int {
	tot, n := 0, len(num)
	cnt := make([]int, 10)
	for _, ch := range num {
		d := int(ch - '0')
		cnt[d]++
		tot += d
	}
	if tot%2 != 0 {
		return 0
	}
	target := tot / 2
	maxOdd := (n + 1) / 2
	comb := make([][]int, maxOdd+1)
	for i := range comb {
		comb[i] = make([]int, maxOdd+1)
		comb[i][i], comb[i][0] = 1, 1
		for j := 1; j < i; j++ {
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD
		}
	}
	dp := make([][]int, target+1)
	for i := range dp {
		dp[i] = make([]int, maxOdd+1)
	}
	dp[0][0] = 1

	psum, totSum := 0, 0
	for i := 0; i < 10; i++ {
		psum += cnt[i]
		totSum += cnt[i] * i
		for oddCnt := min(psum, maxOdd); oddCnt >= max(0, psum-(n-maxOdd)); oddCnt-- {
			evenCnt := psum - oddCnt
			for curr := min(totSum, target); curr >= max(0, totSum-target); curr-- {
				res := 0
				for j := max(0, cnt[i]-evenCnt); j <= min(cnt[i], oddCnt) && i*j <= curr; j++ {
					ways := comb[oddCnt][j] * comb[evenCnt][cnt[i]-j] % MOD
					res = (res + ways*dp[curr-i*j][oddCnt-j]%MOD) % MOD
				}
				dp[curr][oddCnt] = res % MOD
			}
		}
	}
	return dp[target][maxOdd]
}