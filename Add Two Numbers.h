// Add Two Numbers
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// time O(n), space O(1)
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *cur = &dummy;
        for (int carry=0; l1 || l2 || carry; ) {
            int digit = carry;
            if (l1) digit += l1->val, l1 = l1->next;
            if (l2) digit += l2->val, l2 = l2->next;
            carry = digit/10;
            cur = cur->next = new ListNode(digit%10);
        }
        return dummy.next;
    }
};
