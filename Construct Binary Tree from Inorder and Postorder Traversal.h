// Construct Binary Tree from Inorder and Postorder Traversal
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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

// time O(nlogn), space O(logn)
class Solution {
public:
    TreeNode *buildTree(vector<int>& inorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2) {
        if (begin1>end1 || begin2>end2) return nullptr;
        int i = begin1;
        for (; inorder[i] != postorder[end2]; ++i);
        TreeNode *node = new TreeNode(postorder[end2]);
        node->left = buildTree(inorder, begin1, i-1, postorder, begin2, begin2+i-begin1-1);
        node->right = buildTree(inorder, i+1, end1, postorder, begin2+i-begin1, end2-1);
        return node;
    }
    
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
