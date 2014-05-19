// Linked List Cycle II
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> hash;
        while (head) {
            if (hash.find(head) != hash.end()) return head;
            hash.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

// Two Pointers Version, 2(a+b)= a+b+(b+c)n, time complexity O(n), space complexity O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (true) {
            if (!fast || !fast->next) return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};