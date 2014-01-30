// Add Two Numbers
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode header(0), *cur = &header;
        int carryBit = 0;
        while (l1 || l2 || carryBit) {
            int digit = carryBit;
            if (l1) digit += l1->val, l1 = l1->next;
            if (l2) digit += l2->val, l2 = l2->next;
            carryBit = digit>=10 ? 1: 0;
            digit %= 10;
            cur->next = new ListNode(digit);
            cur = cur->next;
        }
        return header.next;
    }
};