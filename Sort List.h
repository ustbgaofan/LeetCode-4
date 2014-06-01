// Sort List
/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Merge Sort with Recursion
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(fast);
        ListNode dummy(0);
        head = &dummy;
        while (head1 && head2) {
            if (head1->val > head2->val) {
                head->next = head2;
                head2 = head2->next;
            } else {
                head->next = head1;
                head1 = head1->next;
            }
            head = head->next;
        }
        if (head1) head->next = head1;
        if (head2) head->next = head2;
        return dummy.next;
    }
};

// Quick Sort with Recursion
class Solution {
public:
    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (head==tail || head->next==tail) return head;
        ListNode *pre = head, *post = head;
        while (post->next && post->val==post->next->val) post = post->next;
        ListNode *lastHead = post; 
        for (ListNode *cur=post->next; cur!=tail; ) {
            if (cur->val < head->val) {
                post->next = cur->next;
                ListNode *t = pre;
                pre = cur;
                pre->next = t;
                cur = post->next;
            } else {
                post = cur;
                cur = cur->next;
            }
        }
        pre = sortList(pre, head);
        lastHead->next = sortList(lastHead->next, tail);
        return pre;
    }
    
    ListNode *sortList(ListNode *head) {
        return sortList(head, NULL);
    }
};

// Merge Sort without Recursion
class Solution {
public:
    void handleRight(ListNode *&r, ListNode *&k, int &rCount) {
        k = k->next = r;
        r = r->next;
        ++rCount;
    }
    
    void handleLeft(ListNode *&l, ListNode *&k, int &lCount) {
        ListNode *next = l->next;
        if (k->next != l) {
            l->next = k->next;
            k->next = l;
        }
        k = k->next;
        l = next;
        ++lCount;
    }
    
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        bool bStop = false;
        for (int w=1; !bStop; w<<=1) {
            ListNode *k = &dummy;
            while (k->next) {
                ListNode *l = k->next, *r = k->next;
                for (int i=0; i<w && r; ++i) r = r->next;
                if (l==dummy.next && !r) { bStop = true; break; }
                int lCount = 0, rCount = 0;
                while (l && lCount<w && r && rCount<w) {
                    if (l->val > r->val) handleRight(r, k, rCount);
                    else handleLeft(l, k, lCount);
                }
                while (l && lCount<w) handleLeft(l, k, lCount);
                while (r && rCount<w) handleRight(r, k, rCount);
            }
        }
        return dummy.next;
    }
};

// Quick Sort without Recursion
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        stack<pair<ListNode *, ListNode *>> stk;
        stk.push(make_pair(&dummy, (ListNode *)NULL));
        while (!stk.empty()) {
            pair<ListNode *, ListNode *> p = stk.top();
            stk.pop();
            ListNode *head = p.first->next, *pre = head, *post = head;
            while (post->next!=p.second && post->val==post->next->val) post = post->next;
            ListNode *lastHead = post;
            for (ListNode *cur=post->next; cur!=p.second; ) {
                if (cur->val < head->val) {
                    post->next = cur->next;
                    ListNode *t = pre;
                    pre = cur;
                    pre->next = t;
                    cur = post->next;
                } else {
                    post = cur;
                    cur = cur->next;
                }
            }
            p.first->next = pre;
            if (pre != head) stk.push(make_pair(p.first, head));
            if (lastHead->next != p.second) stk.push(make_pair(lastHead, p.second));
        }
        return dummy.next;
    }
};