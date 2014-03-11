// Construct Binary Tree from Preorder and Inorder Traversal
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, int begin1, int end1, vector<int> &inorder, int begin2, int end2) {
        if (begin1>end1 || begin2>end2) return NULL;
        int i = begin2;
        for (; inorder[i] != preorder[begin1]; ++i);
        TreeNode *node = new TreeNode(preorder[begin1]);
        node->left = buildTree(preorder, begin1+1, begin1+i-begin2, inorder, begin2, i-1);
        node->right= buildTree(preorder, begin1+i-begin2+1, end1, inorder, i+1, end2);
        return node;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};