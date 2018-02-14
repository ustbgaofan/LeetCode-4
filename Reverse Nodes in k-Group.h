// Reverse Nodes in k-Group
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Iterative, time O(n), space O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0), *slow = &dummy, *fast = &dummy;
        dummy.next = head;
        while (true) {
            for (int i=0; i<k && fast; ++i) fast = fast->next;
            if (!fast) return dummy.next;
            ListNode* newHead = fast->next, *oldHead = slow->next;
            fast->next = nullptr;
            slow->next = ReverseList(oldHead);
            oldHead->next = newHead;
            slow = fast = oldHead;
        }
    }
    
    ListNode* ReverseList(ListNode* head) {
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

// Recursive, time O(n), space O(n/k)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i=0; i<k-1 && cur; ++i) cur = cur->next;
        if (!cur) return head;
        ListNode* nextHead = cur->next;
        cur->next = nullptr;
        cur = head;
        head = reverseList(head);
        cur->next = reverseKGroup(nextHead, k);
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            ListNode* newHead = cur->next;
            cur->next = newHead->next;
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};
