# Link: https://leetcode.cn/problems/remove-invalid-parentheses/
# Level: Hard
# Date: 2025-05-12

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def is_valid(string):
            cnt = 0
            for ch in string:
                if ch == "(":
                    cnt += 1
                elif ch == ")":
                    cnt -= 1
                    if cnt < 0:
                        return False
            return cnt == 0
        
        res = []
        visited = set()
        queue = deque([s])
        visited.add(s)
        found = False
        while queue:
            level_size = len(queue)
            current_level = set()
            for _ in range(level_size):
                current = queue.popleft()
                if is_valid(current):
                    res.append(current)
                    found = True

                if not found:
                    for i in range(len(current)):
                        if current[i] not in "()":
                            continue
                        new_str = current[:i] + current[i+1:]
                        if new_str not in visited:
                            current_level.add(new_str)
                            visited.add(new_str)
            if found:
                break
            queue.extend(current_level)
        return res
