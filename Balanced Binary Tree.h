// Balanced Binary Tree
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// time O(nlogn), space O(h)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(getTreeDepth(root->left)-getTreeDepth(root->right)) >1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getTreeDepth(TreeNode* root) {
        if (!root) return 0;
        return max(getTreeDepth(root->left), getTreeDepth(root->right)) + 1;
    }
};

// time O(n), space O(h) 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth;
        return isBalanced(root, depth);
    }
    
    bool isBalanced(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        int l, r;
        if (!isBalanced(root->left, l)) return false;
        if (!isBalanced(root->right, r)) return false;
        if (abs(l-r) > 1) return false;
        depth = 1 + max(l, r);
        return true;
    }
};
