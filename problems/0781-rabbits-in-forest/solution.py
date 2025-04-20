# Link: https://leetcode.cn/problems/rabbits-in-forest/
# Level: Medium
# Date: 2025-04-20

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        res = 0
        cnt = defaultdict(int)
        for ans in answers:
            if cnt[ans] == 0:
                res += ans + 1
            cnt[ans] += 1
            if cnt[ans] == ans + 1:
                cnt[ans] = 0
        return res
