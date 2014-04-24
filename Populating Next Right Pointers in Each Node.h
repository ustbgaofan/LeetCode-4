// Populating Next Right Pointers in Each Node
/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// Iterative Version with Queue(general), time complexity O(n), space complexity O(n)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (root) {
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
                root->next = q.front();
            } else if (!q.empty()) {
                q.push(NULL);
            }
        }
    }
};

// Recursive Version(not general), time complexity O(n), space complexity O(h)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root || !root->left) return;
        root->left->next = root->right;
        root->right->next = root->next? root->next->left: NULL;
        connect(root->left);
        connect(root->right);
    }
};

// Iterative Version without Queue(not general), time complexity O(n), space complexity O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root && root->left) {
            TreeLinkNode *cur = root;
            while (cur) {
                cur->left->next = cur->right;
                cur->right->next = cur->next? cur->next->left: NULL;
                cur = cur->next;
            }
            root = root->left;    
        }
    }
};