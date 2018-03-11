// Copy List with Random Pointer
/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// Hash, time O(n), space O(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> h;
        h[nullptr] = nullptr;  // corner case!
        RandomListNode dummy(0), *cur = &dummy;
        for (; head; head=head->next) {
            if (h.find(head) == h.end()) {
                h[head] = new RandomListNode(head->label);
            }
            if (h.find(head->random) == h.end()) {
                h[head->random] = new RandomListNode(head->random->label);
            }
            cur->next = h[head];
            cur = cur->next;
            cur->random = h[head->random];
        }
        return dummy.next;
    }
};

// time O(n), space O(1)
// associate the original node with its copy node in a single linked list
// 1. Iterate the original list and duplicate each node. The duplicate of each node follows its original immediately.
// 2. Iterate the new list and assign the random pointer for each duplicated node.
// 3. Restore the original list and extract the duplicated nodes.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        for (RandomListNode *cur=head; cur; cur=cur->next->next) {
            RandomListNode *t = new RandomListNode(cur->label);
            t->next = cur->next;
            cur->next = t;
        }
        for (RandomListNode *cur=head; cur; cur=cur->next->next) {
            if (cur->random) cur->next->random = cur->random->next;
        }
        RandomListNode *res = head->next;
        for (RandomListNode *cur=head; cur; cur=cur->next) {
            RandomListNode *next = cur->next->next;
            if (next) cur->next->next = next->next;
            cur->next = next;
        }
        return res;
    }
};
