// Swap Nodes in Pairs 
/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode header(0);
        header.next = head;
        ListNode *p1 = &header, *p2 = head;
        while (p1 && p2 && p2->next) {
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
        return header.next;
    }
};

// Recursive Version 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *newHead = head->next;
        head->next = newHead->next;
        newHead->next = head;
        head->next = swapPairs(head->next);
        return newHead;
    }
};