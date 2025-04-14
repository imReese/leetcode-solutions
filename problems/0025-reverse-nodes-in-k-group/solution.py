# Link: https://leetcode.cn/problems/reverse-nodes-in-k-group/
# Level: Hard
# Date: 2025-04-14

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head: Optional[ListNode], tail: Optional[ListNode]) -> Tuple[ListNode, ListNode]:
        prev = tail.next
        p = head
        while prev != tail:
            nex = p.next
            p.next = prev
            prev = p
            p = nex
        return tail, head

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        hair = ListNode(0)
        hair.next = head
        pre = hair
        while head:
            tail = pre

            for i in range(k):
                tail = tail.next
                if not tail:
                    return hair.next

            nex = tail.next
            head, tail = self.reverse(head, tail)
            pre.next = head        
            tail.next = nex
            pre = tail
            head = tail.next
        return hair.next
