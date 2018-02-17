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

// BFS, time O(n), space O(n)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            for (int i=0; i<k; ++i) {
                TreeLinkNode* f = q.front();
                q.pop();
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                f->next = i==k-1? nullptr: q.front();
            }
        }
    }
};

// Dummy head iterative, time O(n), space O(1)
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
