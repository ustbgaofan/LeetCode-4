// Merge Two Sorted Lists 
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Version 1, creating new nodes, retain the original lists 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode header(0), *cur = &header;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while (l1) {
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2) {
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
            cur = cur->next;
        }
        return header.next;
    }
};

// Version 2, using old nodes, destroy the original lists 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode header(0), *cur = &header;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return header.next;
    }
};