// Merge k Sorted Lists
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        struct MyComp {
            bool operator() (ListNode *node1, ListNode *node2) {
                return node1->val > node2->val;
            }
        };
        priority_queue<ListNode *, vector<ListNode *>, MyComp> pq;
        for (int i=0; i<lists.size(); ++i) {
            if (lists[i]) pq.push(lists[i]);
        }
        ListNode header(0), *cur = &header;
        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            if (node->next) pq.push(node->next);
            cur = cur->next = node;
        }
        return header.next;
    }
};