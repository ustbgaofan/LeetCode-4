// Reverse Linked List II 
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Two-pass Version, time O(n), space O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        for (int i=0; i<m-1; ++i) prev = prev->next;
        ListNode *newHead = prev->next, *cur = prev;
        for (int i=0; i<=n-m; ++i) cur = cur->next;
        ListNode *nextHead = cur->next;
        cur->next = nullptr;
        prev->next = reverseList(newHead);
        newHead->next = nextHead;
        return dummy.next;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* newHead = cur->next;
            cur->next = newHead->next;
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};

// One-pass Version, time O(n), space O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        for (int i=0; i<m-1; ++i) prev = prev->next;
        ListNode* cur = prev->next;
        for (int i=0; i<n-m; ++i) {
            ListNode* newHead = cur->next;
            cur->next = newHead->next;
            newHead->next = prev->next;
            prev->next = newHead;
        }
        return dummy.next;
    }
};
