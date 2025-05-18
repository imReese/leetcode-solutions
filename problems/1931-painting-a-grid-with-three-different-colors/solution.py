# Link: https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/
# Level: Hard
# Date: 2025-05-18

class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        MOD = 10**9 + 7

        def isValidColumns(s):
            prev = -1
            for _ in range(m):
                color = s % 3
                if color == prev:
                    return False
                prev = color
                s //= 3
            return True
        
        valid_states = [s for s in range(3**m) if isValidColumns(s)]
        k = len(valid_states)
        if k == 0:
            return 0
        
        transitions = {}
        state_to_index = {s:i for i, s in enumerate(valid_states)}
        for s1 in valid_states:
            transitions[s1] = []
            for s2 in valid_states:
                if self.canTransfer(s1, s2, m):
                    transitions[s1].append(s2)
        dp_prev = [1] * k
        for _ in range(1, n):
            dp_curr = [0] * k
            for i in range(k):
                s1= valid_states[i]
                for s2 in transitions[s1]:
                    j = state_to_index[s2]
                    dp_curr[j] = (dp_curr[j] + dp_prev[i]) % MOD
            dp_prev = dp_curr
        return sum(dp_prev) % MOD

    def canTransfer(self, s1, s2, m):
        for _ in range(m):
            if s1 % 3 == s2 % 3:
                return False
            s1 //= 3
            s2 //= 3
        return True
