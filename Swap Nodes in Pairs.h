// Swap Nodes in Pairs 
/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0), *p1 = &dummy, *p2 = head;
        dummy.next = head;
        while (p1 && p2 && p2->next) {
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
        return dummy.next;
    }
};

// Recursive, time O(n), space O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = head->next;
        head->next = newHead->next;
        newHead->next = head;
        head->next = swapPairs(head->next);
        return newHead;
    }
};
