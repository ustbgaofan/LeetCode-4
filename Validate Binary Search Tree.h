// Validate Binary Search Tree
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
 
// Upper and Lower Bound, time O(n), space O(h)
class Solution {
public:   
    bool isValidBST(TreeNode *root) {
        return preorder(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool preorder(TreeNode *root, long long lower, long long upper) {
        if (!root) return true;
        if (root->val<=lower || root->val>=upper) return false;
        return preorder(root->left, lower, root->val) && 
               preorder(root->right, root->val, upper);
    }
};

// Inorder, time O(n), space O(h)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return inorder(root, pre);
    }
    
    bool inorder(TreeNode* root, TreeNode*& pre) {
        if (!root) return true;
        if (!inorder(root->left, pre)) return false;
        if (pre && root->val <= pre->val) return false;
        return inorder(root->right, pre = root);
    }
};
