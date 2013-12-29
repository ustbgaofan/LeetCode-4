// Minimum Depth of Binary Tree
/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
 
// Recursive Version 
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;  // included in left && right
        if (root->left && !root->right) return 1 + minDepth(root->left); 
        if (!root->left && root->right) return 1 + minDepth(root->right);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// Iterative Version, NULL is a level separator
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int depth = 0;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                ++depth;
                q.push(NULL);
            } else {
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (!node->left && !node->right) return ++depth;
            }
        }
    }
};