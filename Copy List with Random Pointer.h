// Copy List with Random Pointer
/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


// 1st Hash-based Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> hash;
        hash[NULL] = NULL;
        for (RandomListNode *cur=head; cur; cur=cur->next) {
            hash[cur] = new RandomListNode(cur->label);
        }
        for (RandomListNode *cur=head; cur; cur=cur->next) {
            hash[cur]->next = hash[cur->next];
            hash[cur]->random = hash[cur->random];
        }
        return hash[head];
    }
};

// 2nd Hash-based Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> hash;
        hash[NULL] = NULL;
        RandomListNode dummy(0), *newHead = &dummy;
        for (; head; head=head->next) {
            if (hash.find(head) == hash.end()) {
                hash[head] = new RandomListNode(head->label);
            }
            if (hash.find(head->random) == hash.end()) {
                hash[head->random] = new RandomListNode(head->random->label);
            }
            newHead->next = hash[head];
            newHead = newHead->next;
            newHead->random = hash[head->random];
        }
        return dummy.next;
    }
};

// Non-hash Version, time complexity O(n), space complexity O(1)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        for (RandomListNode *cur=head; cur; cur=cur->next->next) {
            RandomListNode *newCur = new RandomListNode(cur->label);
            newCur->next = cur->next;
            cur->next = newCur;
        }
        for (RandomListNode *cur=head; cur; cur=cur->next->next) {
            if (cur->random) cur->next->random = cur->random->next;
        }
        RandomListNode *newHead = head->next;
        for (RandomListNode *cur=head; cur; cur=cur->next) {
            RandomListNode *next = cur->next->next;
            if (next) cur->next->next = next->next;
            cur->next = next;
        }
        return newHead;
    }
};