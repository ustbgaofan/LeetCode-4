// Insertion Sort List
/*
Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        for (ListNode *cur=head; cur->next; ) {
            if (cur->next->val >= cur->val) {
                cur = cur->next; 
                continue;
            }
            for (ListNode *ins=&dummy; ins!=cur; ins=ins->next) {
                if (cur->next->val < ins->next->val) {
                    ListNode *del = cur->next;
                    cur->next = del->next;
                    del->next = ins->next;
                    ins->next = del;
                    break;
                }
            }
        }
        return dummy.next;
    }
};