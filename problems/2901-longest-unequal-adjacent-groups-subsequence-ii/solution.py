# Link: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/
# Level: Medium
# Date: 2025-05-16

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        def is_adjacent(a: str, b: str) -> bool:
            if len(a) != len(b):
                return False
            diff = 0
            for x, y in zip(a, b):
                if x != y:
                    diff += 1
                    if diff > 1:
                        return False
            return diff == 1
        
        n = len(words)
        dp = [1] * n
        prev = [-1] * n
        max_len = 1
        max_idx = 0

        for i in range(n):
            for j in range(i):
                if groups[i] != groups[j] and is_adjacent(words[i], words[j]):
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        prev[i] = j
            if dp[i] > max_len:
                max_len = dp[i]
                max_idx = i
            elif dp[i] == max_len:
                max_idx = i

        path = []
        curr = max_idx
        while curr != -1:
            path.append(words[curr])
            curr = prev[curr]
        path.reverse()
        res = []
        for i in range(len(path)):
            res.append(path[i])
        return res
