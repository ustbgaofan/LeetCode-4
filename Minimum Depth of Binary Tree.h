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
 
// Recursive, time O(n), space O(h)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && !root->right) return 1 + minDepth(root->left);
        if (!root->left && root->right) return 1 + minDepth(root->right);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// Iterative, time O(n), space O(n)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                ++res;
                q.push(nullptr);
            } else {
                if (!node->left && !node->right) return res+1;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};
