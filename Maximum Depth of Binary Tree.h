// Maximum Depth of Binary Tree
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Iterative Version, NULL is a level separator
class Solution {
public:
    int maxDepth(TreeNode *root) {
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
                if (q.empty()) return depth;
                q.push(NULL);
            } else {
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};