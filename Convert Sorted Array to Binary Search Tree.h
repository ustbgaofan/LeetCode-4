// Convert Sorted Array to Binary Search Tree
/* 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
	TreeNode *sortedArrayToBST(vector<int> &num, int begin, int end) {
        if (begin > end) return NULL;
        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, begin, mid-1);
        root->right = sortedArrayToBST(num, mid+1, end);
        return root;
    }
	
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};