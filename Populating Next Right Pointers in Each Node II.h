// Populating Next Right Pointers in Each Node II
/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// Iterative Version with Queue, time complexity O(n), space complexity O(n)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(nullptr);
        while (q.size() > 1) {
            TreeLinkNode* f = q.front();
            q.pop();
            if (!f) {
                q.push(nullptr);
                continue;
            }
            if (f->left) q.push(f->left);
            if (f->right) q.push(f->right);
            f->next = q.front();
        }
        return;
    }
};

// (Not suggested) Recursive Version, time complexity O(n), space complexity O(h)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left && root->right) root->left->next = root->right;
        TreeLinkNode *next = root->next;
        while (next && !next->left && !next->right) next = next->next;
        if (next) {
            if (root->right) root->right->next = next->left? next->left: next->right;
            else if (root->left) root->left->next = next->left? next->left: next->right;
        }
        connect(root->right);  // right first
        connect(root->left);   // left second
    }
};

// (Not suggested) Advanced Iterative Version 1, time complexity O(n), space complexity O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *cur = root;
            root = root->left? root->left: (root->right? root->right: NULL);
            while (cur) {
                if (cur->left && cur->right) cur->left->next = cur->right;
                TreeLinkNode *next = cur->next;
                while (next && !next->left && !next->right) next = next->next;
                if (next) {
                    if (cur->right) cur->right->next = next->left? next->left: next->right;
                    else if (cur->left) cur->left->next = next->left? next->left: next->right;
                    if (!root) root = next->left? next->left: next->right;
                }
                cur = next;
            }
        }
    }
};

// (Not suggested) Advanced Iterative Version 2, time complexity O(n), space complexity O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *cur = root, *prev = NULL;
            root = NULL;
            while (cur) {
                if (cur->left || cur->right) {
                    if (prev) prev->next = cur->left? cur->left: cur->right;
                    prev = cur->right? cur->right: cur->left;
                    if (cur->left) cur->left->next = cur->right;
                    if (!root) root = cur->left? cur->left: cur->right;
                }
                cur = cur->next;
            }
        }
    }
};

// Dummy head recursive version, time complexity O(n), space complexity O(h)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode dummy(0), *cur = &dummy;
        if (root->left) {
            cur->next = root->left;
            cur = cur->next;
        }
        if (root->right) {
            cur->next = root->right;
            cur = cur->next;
        }
        TreeLinkNode *next = root->next; 
        while (next && !next->left && !next->right) next = next->next;
        if (next) {
            cur->next = next->left ? next->left : next->right;
        }
        connect(root->right);  // right first
        connect(root->left);   // left second
    }
};

// Dummy head iterative version, time complexity O(n), space complexity O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode dummy(0), *cur = &dummy;
            while (root) {
                if (root->left) {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = dummy.next;
        }
    }
};
