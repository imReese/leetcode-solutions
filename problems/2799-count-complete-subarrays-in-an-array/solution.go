// Link: https://leetcode.cn/problems/count-complete-subarrays-in-an-array/
// Level: Medium
// Date: 2025-04-24

func countCompleteSubarrays(nums []int) int {
	res := 0
	cnt := make(map[int]int)
	n := len(nums)
	distinct := make(map[int]bool)
	for _, num := range nums {
		distinct[num] = true
	}
	distinctCount := len(distinct)
	right := 0
	for left := 0; left < n; left++ {
		if left > 0 {
			remove := nums[left-1]
			cnt[remove]--
			if cnt[remove] == 0 {
				delete(cnt, remove)
			}
		}
		for right < n && len(cnt) < distinctCount {
			add := nums[right]
			cnt[add]++
			right++
		}
		if len(cnt) == distinctCount {
			res += (n - right + 1)
		}
	}

	return res
}