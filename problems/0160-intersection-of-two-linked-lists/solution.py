# Link: https://leetcode.cn/problems/intersection-of-two-linked-lists/
# Level: Easy
# Date: 2025-05-11

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if headA is None or headB is None:
            return None
        curA, curB = headA, headB
        while curA != curB:
            curA = curA.next if curA else headB
            curB = curB.next if curB else headA
        return curA
