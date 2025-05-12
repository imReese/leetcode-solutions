# Link: https://leetcode.cn/problems/finding-3-digit-even-numbers/
# Level: Easy
# Date: 2025-05-12

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        n = len(digits)
        if n < 3:
            return []
        s = set()
        for i in range(n):
            if digits[i] == 0:
                continue
            for j in range(n):
                if j == i:
                    continue
                for k in range(n):
                    if k == i or k == j or digits[k] % 2 != 0:
                        continue
                    s.add(digits[i]*100 + digits[j]*10 + digits[k])
        return sorted(s)
