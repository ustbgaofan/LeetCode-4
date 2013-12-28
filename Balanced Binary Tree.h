// Balanced Binary Tree
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
 
// Slow Version, O(nlogn) if workload is divided equally 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (abs(getTreeDepth(root->left)-getTreeDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getTreeDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(getTreeDepth(root->left), getTreeDepth(root->right));
    }
};

// Fast Version, O(n) if workload is divided equally 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int height;
        return isBalanced(root, height);
    }
    
    bool isBalanced(TreeNode *root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        int leftHeight, rightHeight;
        if (!isBalanced(root->left, leftHeight)) return false;
        if (!isBalanced(root->right, rightHeight)) return false;
        if (abs(rightHeight - leftHeight) > 1) return false;
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};