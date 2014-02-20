// Rotate List
/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Version 1 
class Solution {
public:
    int getListLength(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        int len = getListLength(head);
        k %= len;
        if (k == 0) return head;
        ListNode *fwd = head, *newHead = head;
        for (int i=0; i<k; ++i) fwd = fwd->next;
        while (fwd->next) {
            newHead = newHead->next;
            fwd = fwd->next;
        }
        ListNode *tmp = newHead->next;
        newHead->next = NULL;
        fwd->next = head;
        head = tmp;
        return head;
    }
};

// Version 2
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        ListNode *tail = head;
        int len = 1;
        while (tail->next) {
            ++len;
            tail = tail->next;
        }
        k = k % len;
        if (k == 0) return head;
        int jump = len - k - 1;
        ListNode *cur = head;
        for (int i=0; i<jump; ++i) cur = cur->next;
        ListNode *newHead = cur->next;
        cur->next = NULL;
        tail->next = head;
        head = newHead;
        return head;
    }
};