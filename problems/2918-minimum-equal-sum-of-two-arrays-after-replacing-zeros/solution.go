// Link: https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
// Level: Medium
// Date: 2025-05-10

func minSum(nums1 []int, nums2 []int) int64 {
	var sum1, zero1 int64 = 0, 0
	for _, x := range nums1 {
		if x == 0 {
			zero1++
		}
		sum1 += int64(x)
	}
	var sum2, zero2 int64 = 0, 0
	for _, x := range nums2 {
		if x == 0 {
			zero2++
		}
		sum2 += int64(x)
	}

	s1 := sum1 + zero1
	s2 := sum2 + zero2

	if zero1 == 0 && zero2 == 0 {
		if sum1 == sum2 {
			return sum1
		} else {
			return -1
		}
	} else if zero1 == 0 {
		if sum1 >= s2 {
			return sum1
		} else {
			return -1
		}
	} else if zero2 == 0 {
		if sum2 >= s1 {
			return sum2
		} else {
			return -1
		}
	} else {
		if s1 >= s2 {
			return s1
		} else {
			return s2
		}
	}
}
