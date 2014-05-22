// Reorder List 
/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Pointers Stored Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) return;
        vector<ListNode *> pointers;
        for (ListNode *cur=head; cur; cur=cur->next) {
            pointers.push_back(cur);
        }
        int N = pointers.size();
        for (int i=0, j=N-1; i+1<j; ++i, --j) {
            pointers[i]->next = pointers[j];
            pointers[j]->next = pointers[i+1];
        }
        pointers[N>>1]->next = NULL;
    }
};

// Reverse & Merge Version, time complexity O(n), space complexity O(1)
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        for (fast=slow->next; fast->next; ) {
            ListNode *ins = fast->next;
            fast->next = ins->next;
            ins->next = slow->next;
            slow->next = ins;
        }
        for (fast=slow->next; head->next && head->next->next; fast=slow->next) {
            slow->next = fast->next;
            fast->next = head->next;
            head->next = fast;
            head = fast->next;
        }
    }
};