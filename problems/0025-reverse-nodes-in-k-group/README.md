# 25. K 个一组翻转链表 (Reverse Nodes in k-Group)

[LeetCode 原题链接](https://leetcode.cn/problems/reverse-nodes-in-k-group/) | 难度: **困难** | 标签: `递归`、`链表`

## 题目描述

给你链表的头节点 `head`, 每 _`k`_ 个节点一组进行翻转, 请你返回修改后的链表.

`k` 是一个正整数, 它的值小于或等于链表的长度. 如果节点总数不是 _`k`_ 的整数倍, 那么请将最后剩余的节点保持原有顺序.

你不能只是单纯的改变节点内部的值, 而是需要实际进行节点交换.

示例:

![25. K 个一组翻转链表 - 示例](/problems/0025-reverse-nodes-in-k-group/ex.png)

```plaintext
输入: head = [1,2,3,4,5], k = 2
输出: [2,1,4,3,5]
```

## 解法思路

### 模拟

- 核心思想: 每次翻转前, 先判断是否有 k 个节点, 如果不足 k 个, 直接返回 head 即可. 然后翻转这 k 个节点, 翻转后, 这 k 个节点的头变成了尾, 尾变成了头, 因此需要返回新的头与尾.
- 时间复杂度: O(n)
- 空间复杂度: O(1)

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
        pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
            ListNode* prev = tail->next;
            ListNode* p = head;
            while (prev != tail) {
                ListNode* nex = p->next;
                p->next = prev;
                prev = p;
                p = nex;
            }
            return {tail, head};
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* hair = new ListNode();
            hair->next = head;
            ListNode* pre = hair;
            while (head) {
                ListNode* tail = pre;
                for (int i = 0; i < k; i++) {
                    tail = tail->next;
                    if (!tail) {
                        return hair->next;
                    }
                }
                ListNode* nex = tail->next;
                pair<ListNode*, ListNode*> result = reverse(head, tail);
                head = result.first;
                tail = result.second;
                pre->next = head;
                tail->next = nex;
                pre = tail;
                head = tail->next;
            }
            return hair->next;
        }
};
```

## 相似题目

- [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

## Tags

[递归](/tags/recursion.md) | [链表](/tags/linked-list.md)
