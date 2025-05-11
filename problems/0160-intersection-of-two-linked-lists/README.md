# 160. 相交链表 (Intersection of Two Linked Lists)

[LeetCode 原题链接](https://leetcode.cn/problems/intersection-of-two-linked-lists/) | 难度: **简单** | 标签: `哈希表`、`链表`、`双指针`

## 题目描述

给你两个单链表的头节点 `headA` 和 `headB`, 请你找出并返回两个单链表相交的起始节点. 如果两个链表不存在相交节点, 返回 `null`.

图示两个链表在节点 `c1` 开始相交:

![160. 相交链表 - 描述](/problems/0160-intersection-of-two-linked-lists/description.png)

题目数据 **保证** 整个链式结构中不存在环.

**注意**, 函数返回结果后, 链表必须 **保持其原始结构**.

**自定义评测:**

**评测系统** 的输入如下(你设计的程序 **不适用** 此输入):

- `intersectVal` - 相交的起始节点的值. 如果不存在相交节点, 这一值为 `0`
- `listA` - 第一个链表
- `listB` - 第二个链表
- `skipA` - 在 `listA` 中（从头节点开始）跳到交叉节点的节点数
- `skipB` - 在 `listB` 中（从头节点开始）跳到交叉节点的节点数

评测系统将根据这些输入创建链式数据结构, 并将两个头节点 `headA` 和 `headB` 传递给你的程序. 如果程序能够正确返回相交节点, 那么你的解决方案将被 **视作正确答案**.

示例:

![160. 相交链表 - 示例](/problems/0160-intersection-of-two-linked-lists/ex.png)

```plaintext
输入: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出: Intersected at '8'
解释:
  - 相交节点的值为 8 (注意, 如果两个链表相交则不能为 0).
  - 从各自的表头开始算起, 链表 A 为 [4,1,8,4,5], 链表 B 为 [5,6,1,8,4,5].
  - 在 A 中, 相交节点前有 2 个节点；在 B 中, 相交节点前有 3 个节点.
  - 请注意相交节点的值不为 1, 因为在链表 A 和链表 B 之中值为 1 的节点 (A 中第二个节点和 B 中第三个节点) 是不同的节点. 换句话说, 它们在内存中指向两个不同的位置, 而链表 A 和链表 B 中值为 8 的节点 (A 中第三个节点, B 中第四个节点) 在内存中指向相同的位置.
```

## 解法思路

### 双指针

- 核心思想: 两个指针分别从两个链表头开始走, 走到尾后再从另一个链表头开始走. 这样两个指针走的距离是一样的, 如果有交点, 那么一定会在交点相遇.
- 时间复杂度: O(m+n) m 为链表 A 的长度, n 为链表 B 的长度.
- 空间复杂度: O(1)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb) {
            pa = (pa == nullptr) ? headB : pa->next;
            pb = (pb == nullptr) ? headA : pb->next;
        }
        return pa;
    }
};
```

## 相似题目

- [599. 两个列表的最小索引总和](https://leetcode.cn/problems/minimum-index-sum-of-two-lists/)

## Tags

[哈希表](/tags/hash-table.md) | [链表](/tags/linked-list.md) | [双指针](/tags/two-pointers.md)
