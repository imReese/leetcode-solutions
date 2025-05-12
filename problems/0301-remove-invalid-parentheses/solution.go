// Link: https://leetcode.cn/problems/remove-invalid-parentheses/
// Level: Hard
// Date: 2025-05-12

func removeInvalidParentheses(s string) []string {
	res := []string{}
	queue := []string{s}
	visited := make(map[string]bool)
	visited[s] = true
	found := false

	for len(queue) > 0 {
		levelSize := len(queue)
		curLevel := make(map[string]bool)

		for i := 0; i < levelSize; i++ {
			cur := queue[0]
			queue = queue[1:]

			if isValid(cur) {
				res = append(res, cur)
				found = true
			}
			if !found {
				for j := 0; j < len(cur); j++ {
					if cur[j] != '(' && cur[j] != ')' {
						continue
					}
					newStr := cur[:j] + cur[j+1:]
					if !visited[newStr] {
						curLevel[newStr] = true
						visited[newStr] = true
					}
				}
			}
		}
		if found {
			break
		}
		for str := range curLevel {
			queue = append(queue, str)
		}
	}
	return res
}

func isValid(s string) bool {
	count := 0
	for _, c := range s {
		if c == '(' {
			count++
		} else if c == ')' {
			count--
			if count < 0 {
				return false
			}
		}
	}
	return count == 0
}
