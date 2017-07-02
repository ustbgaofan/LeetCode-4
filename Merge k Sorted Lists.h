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

// time O(kn), space O(1), assuming length of each list n/k 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode* res = mergeTwoLists(lists[0], lists[1]);
        for (int i=2; i<lists.size(); ++i) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *cur = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (!l1) cur->next = l2;
        if (!l2) cur->next = l1;
        return dummy.next;
    }
};

// time O(nlogk), space O(k), assuming length of each list n/k 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp{
            bool operator()(ListNode* x, ListNode* y) { return x->val > y->val;}
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;  // default great heap
        for (int i=0; i<lists.size(); ++i) {
            if (lists[i]) pq.push(lists[i]);
        }
        ListNode dummy(0), *cur = &dummy;
        while (!pq.empty()) {
            ListNode* t = pq.top();
            pq.pop();
            if (t->next) pq.push(t->next);
            cur = cur->next = t;
        }
        return dummy.next;
    }
};
