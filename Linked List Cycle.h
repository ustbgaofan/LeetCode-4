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

// Naive Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> hash;
        while (head) {
            if (hash.find(head) != hash.end()) return true;
            hash.insert(head);
            head = head->next;
        }
        return false;
    }
};

// Two Pointers Version, time complexity O(n), space complexity O(1)
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