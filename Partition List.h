// Partition List 
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode lheader(0), rheader(0);
        ListNode *lcur = &lheader, *rcur = &rheader;
        while (head) {
            if (head->val < x) {
                lcur->next = head;
                lcur = lcur->next;
            } else {
                rcur->next = head;
                rcur = rcur->next;
            }
            head = head->next;
        }
        rcur->next = NULL;
        lcur->next = rheader.next;
        return lheader.next;
    }
};