// Linked List Cycle
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Hash, time O(n), space O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> h;
        while (head) {
            if (h.find(head) != h.end()) return true;
            h.insert(head);
            head = head->next;
        }
        return false;
    }
};

// Two Pointers, time O(n), space O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (true) {
            if (!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
    }
};
