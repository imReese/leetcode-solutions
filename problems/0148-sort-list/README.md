# 148. 排序链表 (Sort List)

[LeetCode 原题链接](https://leetcode.cn/problems/sort-list/) | 难度: **中等** | 标签: `链表`、`双指针`、`分治`、`排序`、`归并排序`

## 题目描述

给你链表的头结点 `head`, 请将其按 **升序** 排列并返回 **排序后的链表**.

示例:

![148. 排序链表 - 示例](/problems/0148-sort-list/ex.png)

```plaintext
输入: head = [4,2,1,3]
输出: [1,2,3,4]
```

## 解法思路

### 归并排序

- 核心思想: 把链表从中间分开, 递归排序左右两个链表, 然后把两个有序链表合并起来
- 时间复杂度: O(nlogn)
- 空间复杂度：O(logn)

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
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }
};
```

## 相似题目

- [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

## Tags

[链表](/tags/linked-list.md) | [双指针](/tags/two-pointers.md) | [分治](/tags/divide-and-conquer.md) | [排序](/tags/sorting.md) | [归并排序](/tags/merge-sort.md)
