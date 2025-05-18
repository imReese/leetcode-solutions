// Link: https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/
// Level: Hard
// Date: 2025-05-18

const MOD = 1_000_000_007

func colorTheGrid(m int, n int) int {
	validStates := generateValidStates(m)
	k := len(validStates)
	if k == 0 {
		return 0
	}

	transitions := make(map[int][]int)
	stateToIdx := make(map[int]int)
	for i, s := range validStates {
		stateToIdx[s] = i
	}

	for _, s1 := range validStates {
		for _, s2 := range validStates {
			if canTransfer(s1, s2, m) {
				transitions[s1] = append(transitions[s1], s2)
			}
		}
	}

	dpPrev := make([]int, k)
	for i := range dpPrev {
		dpPrev[i] = 1
	}

	for col := 1; col < n; col++ {
		dpCurr := make([]int, k)
		for i, s1 := range validStates {
			for _, s2 := range transitions[s1] {
				j := stateToIdx[s2]
				dpCurr[j] = (dpCurr[j] + dpPrev[i]) % MOD
			}
		}
		dpPrev = dpCurr
	}

	ans := 0
	for _, x := range dpPrev {
		ans = (ans + x) % MOD
	}
	return ans
}

func generateValidStates(m int) []int {
	var valid []int
	total := pow(3, m)
	for s := 0; s < total; s++ {
		if isValidColumn(s, m) {
			valid = append(valid, s)
		}
	}
	return valid
}

func isValidColumn(s int, m int) bool {
	prev := -1
	for i := 0; i < m; i++ {
		color := s % 3
		if color == prev {
			return false
		}
		prev = color
		s /= 3
	}
	return true
}

func canTransfer(s1, s2, m int) bool {
	for i := 0; i < m; i++ {
		if s1%3 == s2%3 {
			return false
		}
		s1 /= 3
		s2 /= 3
	}
	return true
}

func pow(base, exponent int) int {
	result := 1
	for i := 0; i < exponent; i++ {
		result *= base
	}
	return result
}
