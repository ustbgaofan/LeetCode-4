// Remove Duplicates from Sorted List II 
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Iterative Version
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode header(0), *fwd, *bwd;
        fwd = header.next = head;
        bwd = &header;
        while (fwd && fwd->next) {
            if (fwd->val == fwd->next->val) {
                int val = fwd->val;
                while (fwd && fwd->val==val) {
                    bwd->next = fwd->next;
                    delete fwd;
                    fwd = bwd->next;
                }
            } else {
                bwd = bwd->next;
                fwd = fwd->next;
            }
        }
        return header.next;
    }
};

// Recursive Version
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        if (head->val == head->next->val) {
            int val = head->val;
            while (head && head->val==val) {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
            }
            head = deleteDuplicates(head);
        } else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};