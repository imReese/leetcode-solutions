# Link: https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/
# Level: Medium
# Date: 2025-04-04

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def f(root):
            if not root:
                return 0, None
            
            d1, lca1 = f(root.left)
            d2, lca2 = f(root.right)

            if d1 > d2:
                return d1 + 1, lca1
            if d1 < d2:
                return d2 + 1, lca2
            return d1 + 1, root

        return f(root)[1]