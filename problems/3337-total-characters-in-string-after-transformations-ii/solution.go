// Link: https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/
// Level: Hard
// Date: 2025-05-14

const MOD = 1_000_000_007

func lengthAfterTransformations(s string, t int, nums []int) int {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}

	M := buildMatrix(nums)
	mat := matrixPower(M, t)

	res := make([]int, 26)
	for i := 0; i < 26; i++ {
		if cnt[i] == 0 {
			continue
		}
		for j := 0; j < 26; j++ {
			res[j] = (res[j] + mat[i][j]*cnt[i]) % MOD
		}
	}
	total := 0
	for _, v := range res {
		total = (total + v) % MOD
	}
	return total
}

func buildMatrix(nums []int) [][]int {
	M := make([][]int, 26)
	for i := range M {
		M[i] = make([]int, 26)
		for k := 0; k < nums[i]; k++ {
			j := (i + 1 + k) % 26
			M[i][j]++
		}
	}
	return M
}

func matrixPower(base [][]int, power int) [][]int {
	res := make([][]int, len(base))
	for i := range res {
		res[i] = make([]int, len(base))
		res[i][i] = 1
	}

	for power > 0 {
		if power%2 == 1 {
			res = multiply(res, base)
		}
		base = multiply(base, base)
		power /= 2
	}
	return res
}

func multiply(A, B [][]int) [][]int {
	res := make([][]int, len(A))
	for i := range res {
		res[i] = make([]int, len(B[0]))
	}
	for i := 0; i < len(A); i++ {
		for k := 0; k < len(B); k++ {
			if A[i][k] == 0 {
				continue
			}
			for j := 0; j < len(B[0]); j++ {
				res[i][j] = (res[i][j] + A[i][k]*B[k][j]) % MOD
			}
		}
	}
	return res
}
