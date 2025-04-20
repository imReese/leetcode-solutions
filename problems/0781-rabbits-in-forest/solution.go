// Link: https://leetcode.cn/problems/rabbits-in-forest/
// Level: Medium
// Date: 2025-04-20

func numRabbits(answers []int) int {
	res := int(0)
	cnt := make(map[int]int)
	for _, ans := range answers {
		if cnt[ans] == 0 {
			res += ans + 1
		}
		cnt[ans]++
		if cnt[ans] == ans+1 {
			cnt[ans] = 0
		}
	}
	return res
}
