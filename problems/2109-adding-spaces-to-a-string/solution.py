# Link: https://leetcode.cn/problems/adding-spaces-to-a-string/
# Level: Medium
# Date: 2025-03-30

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        ptr = 0
        for i in range(len(s)):
            if ptr < len(spaces) and i == spaces[ptr]:
                ans.append(" ")
                ptr += 1
            ans.append(s[i])
        return "".join(ans)
