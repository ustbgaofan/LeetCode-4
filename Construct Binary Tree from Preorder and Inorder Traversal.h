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

/* time O(nlogn), space O(logn)
Say we have 2 arrays, PRE and IN.
Preorder traversing implies that PRE[0] is the root node.
Then we can find this PRE[0] in IN, say it’s IN[5].
Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it
*/
class Solution {
public:
    TreeNode *buildTree(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2) {
        if (begin1>end1 || begin2>end2) return nullptr;
        int i = begin2;
        for (; inorder[i] != preorder[begin1]; ++i);
        TreeNode *node = new TreeNode(preorder[begin1]);
        node->left = buildTree(preorder, begin1+1, begin1+i-begin2, inorder, begin2, i-1);
        node->right = buildTree(preorder, begin1+i-begin2+1, end1, inorder, i+1, end2);
        return node;
    }
    
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

// time O(n), space O(n)
class Solution {
public:
    TreeNode *buildTree(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2, unordered_map<int, int>& h) {
        if (begin1>end1 || begin2>end2) return nullptr;
        int i = h[preorder[begin1]];
        TreeNode *node = new TreeNode(preorder[begin1]);
        node->left = buildTree(preorder, begin1+1, begin1+i-begin2, inorder, begin2, i-1, h);
        node->right = buildTree(preorder, begin1+i-begin2+1, end1, inorder, i+1, end2, h);
        return node;
    }
    
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> h;
        for (int i=0; i<inorder.size(); ++i) h[inorder[i]] = i;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, h);
    }
};
