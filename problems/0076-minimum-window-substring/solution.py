# Link: https://leetcode.cn/problems/minimum-window-substring/
# Level: Hard
# Date: 2025-04-16

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_cnt = defaultdict(int)
        for c in t:
            t_cnt[c] += 1
        
        required = len(t_cnt)
        formed = 0
        s_cnt = defaultdict(int)
        left = 0
        min_len = float('inf')
        ans_left = 0

        for right in range(len(s)):
            c = s[right]
            s_cnt[c] += 1

            if c in t_cnt and s_cnt[c] == t_cnt[c]:
                formed += 1

                # 当窗口满足条件时，尝试收缩左边界
                while left <= right and formed == required:
                    if right - left + 1 < min_len:
                        min_len = right - left + 1
                        ans_left = left
                    
                    left_c = s[left]
                    s_cnt[left_c] -= 1
                    if left_c in t_cnt and s_cnt[left_c] < t_cnt[left_c]:
                        formed -= 1
                    left += 1
        
        return s[ans_left:ans_left+min_len] if min_len != float('inf') else ""
