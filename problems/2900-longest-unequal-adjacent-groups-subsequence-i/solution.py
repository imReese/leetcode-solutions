# Link: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/
# Level: Easy
# Date: 2025-05-15

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(groups)
        if n == 0:
            return []

        len0, len1 = 0, 0
        path0, path1 = [], []

        if groups[0] == 0:
            len0 = 1
            path0 = [0]
        else:
            len1 = 1
            path1 = [0]

        for i in range(1, n):
            g = groups[i]
            if g == 0:
                new_path = path0.copy()
                new_len = len0
                if len1 + 1 > new_len:
                    new_len = len1 + 1
                    new_path = path1.copy() + [i]
                if new_len > len0:
                    len0 = new_len
                    path0 = new_path
            else:
                new_path = path1.copy()
                new_len = len1
                if len0 + 1 > new_len:
                    new_len = len0 + 1
                    new_path = path0.copy() + [i]
                if new_len > len1:
                    len1 = new_len
                    path1 = new_path

        return [words[i] for i in (path0 if len0 >= len1 else path1)]
