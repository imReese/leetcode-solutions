# 23. 合并 K 个升序链表 (Merge k Sorted Lists)

[LeetCode 原题链接](https://leetcode.cn/problems/merge-k-sorted-lists/) | 难度: **困难** | 标签: `链表`、`分治`、`堆（优先队列）`、`归并排序`

## 题目描述

给你一个链表数组, 每个链表都已经按升序排列.

请你将所有链表合并到一个升序链表中, 返回合并后的链表.

示例:

```plaintext
输入: lists = [[1,4,5],[1,3,4],[2,6]]
输出: [1,1,2,3,4,4,5,6]
解释: 链表数组如下:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    将它们合并到一个有序链表中得到.
    1->1->2->3->4->4->5->6
```

## 解法思路

### 方法一: 两两合并

- 核心思想: 通过两两合并链表, 逐步减少链表数量直到只剩一个
- 时间复杂度: O(nlogk) n 是所有链表的节点总数, k 是链表数量
- 空间复杂度: O(k)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1 < lists.size()) ? lists[i+1] : nullptr;
                mergedLists.emplace_back(mergeTwo(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
```

### 方法二: 优先队列

- 核心思想: 用最小堆维护所有链表的当前头节点, 每次取最小节点合并, 并更新堆
- 时间复杂度: O(nlogk) n 是所有链表的节点总数, k 是链表数量
- 空间复杂度: O(k)

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, i, node))
        dummy = ListNode(-1)
        curr = dummy
        while heap:
            val, idx, node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(heap, (node.next.val, idx, node.next))
        return dummy.next

```

## 相似题目

- [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

## Tags

[链表](/tags/linked-list.md) | [分治](/tags/divide-and-conquer.md) | [堆（优先队列）](/tags/heap-priority-queue.md) | [归并排序](/tags/merge-sort.md)
