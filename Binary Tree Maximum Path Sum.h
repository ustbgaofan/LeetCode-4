// Binary Tree Maximum Path Sum
/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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

// time O(n), space O(h)
class Solution {
public:
    int maxPathSum(TreeNode *root, int &res) {
        if (!root) return 0;
        int l = maxPathSum(root->left, res);
        int r = maxPathSum(root->right, res);
        int pathSum = max(root->val, max(l,r)+root->val);
        res = max(res, max(pathSum, root->val+l+r));
        return pathSum;
    }
    
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
};
