# Link: https://leetcode.cn/problems/largest-rectangle-in-histogram
# Level: Hard
# Date: 2025-04-12

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        left = [0] * n
        right = [0] * n
        
        mono_stack = list()
        for i in range(n):
            while len(mono_stack) != 0 and heights[mono_stack[-1]] >= heights[i]:
                mono_stack.pop()
            left[i] = mono_stack[-1] if len(mono_stack) != 0 else -1
            mono_stack.append(i)
        
        mono_stack.clear()
        for i in range(n - 1, -1, -1):
            while len(mono_stack) != 0 and heights[mono_stack[-1]] >= heights[i]:
                mono_stack.pop()
            right[i] = mono_stack[-1] if len(mono_stack) != 0 else n
            mono_stack.append(i)
        
        ans = max((right[i] - left[i] - 1) * heights[i] for i in range(n)) if n > 0 else 0
        return ans

        
