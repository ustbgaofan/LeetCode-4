// Validate Binary Search Tree
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
 
// Upper and Lower Bound Version, time O(n), space O(n)
class Solution {
public:
    bool isValidBST(TreeNode *root, long long lower, long long upper) {
        if (!root) return true;
        if (root->val<=lower || root->val>=upper) return false;
        return isValidBST(root->left, lower, root->val) && 
               isValidBST(root->right, root->val, upper);
    }
    
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// In Order Version, time complexity O(n)
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
        pre = root;
        return inorder(root->right, pre);
    }
};
