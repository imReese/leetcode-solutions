// Link: https://leetcode.cn/problems/merge-k-sorted-lists/
// Level: Hard
// Date: 2025-05-14

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}
	mid := len(lists) / 2
	left := mergeKLists(lists[:mid])
	right := mergeKLists(lists[mid:])
	return mergeTwo(left, right)
}

func mergeTwo(a, b *ListNode) *ListNode {
	dummy := &ListNode{}
	curr := dummy
	for a != nil && b != nil {
		if a.Val < b.Val {
			curr.Next = a
			a = a.Next
		} else {
			curr.Next = b
			b = b.Next
		}
		curr = curr.Next
	}
	if a != nil {
		curr.Next = a
	} else {
		curr.Next = b
	}
	return dummy.Next
}
