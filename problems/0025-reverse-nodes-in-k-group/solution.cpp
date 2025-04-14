// Link: https://leetcode.cn/problems/reverse-nodes-in-k-group/
// Level: Hard
// Date: 2025-04-14

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