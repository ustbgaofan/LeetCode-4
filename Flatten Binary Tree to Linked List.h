// Flatten Binary Tree to Linked List
/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive, time O(n), space O(h)
class Solution {
public:
    void flatten(TreeNode *root, TreeNode *&next) {
        if (!root) return;
        if (!root->left && !root->right) {
            root->left = root->right = nullptr;
            next = root;
            return;
        }
        flatten(root->right, next);
        flatten(root->left, next);
        root->left = nullptr;
        root->right = next;
        next = root;
    }
    
    void flatten(TreeNode *root) {
        TreeNode *next = nullptr;
        flatten(root, next);
    }
};

// Iterative, time O(n), space O(1)
class Solution {
public:
    void flatten(TreeNode *root) {
        while (root) {
            if (root->left) {
                TreeNode *subtree = root->right;
                root->right = root->left;
                root->left = NULL;
                TreeNode *next = root;
                while (next->right) next = next->right;
                next->right = subtree;  // may not be the final place of subtree
            }
            root = root->right;
        }
    }
};
