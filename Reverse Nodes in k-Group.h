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
 
// Iterative Version
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode header(0), *ins = &header;
        header.next = head;
        while (1) {
            ListNode *probe = ins;
            for (int i=0; i<k; ++i) {
                probe = probe->next;
                if (!probe) return header.next;
            }
            for (int i=0; i<k-1; ++i) {
                ListNode *cur = head->next;
                head->next = cur->next;
                cur->next = ins->next;
                ins->next = cur;
            }
            ins = head;
            head = head->next;
        }
    }
};

// Recursive Version
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode header(0);
        header.next = head;
        ListNode *probe = &header;
        for (int i=0; i<k; ++i) {
            probe = probe->next;
            if (!probe) return header.next;
        }
        for (int i=0; i<k-1; ++i) {
            ListNode *cur = head->next;
            head->next = cur->next;
            cur->next = header.next;
            header.next = cur;
        }
        head->next = reverseKGroup(head->next, k);
        return header.next;
    }
};

// time O(n), space O(1)
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

// time O(n), space O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        while (true) {
            ListNode* cur = head;
            int i = 0;
            for (; i<k-1 && cur; ++i) cur = cur->next;
            if (i<k-1 || !cur) return dummy.next;
            ListNode* nextHead = cur->next;
            cur->next = nullptr;
            prev->next = reverseList(head);
            prev = head;
            head = head->next = nextHead;
        }
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

// time O(n), space O(n/k)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int i = 0;
        for (; i<k-1 && cur; ++i) cur = cur->next;
        if (i<k-1 || !cur) return head;
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
