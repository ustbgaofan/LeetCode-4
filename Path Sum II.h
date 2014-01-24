// Path Sum II
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
// Naive Version with more space and time
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        pathSum(res, path, root, sum);
        return res;
    }
    
    void pathSum(vector<vector<int>>& res, vector<int> path, TreeNode *root, int sum) {
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) res.push_back(path);
        if (root->left) pathSum(res, path, root->left, sum-root->val);
        if (root->right) pathSum(res, path, root->right, sum-root->val);
        return;
    }
};

// Improved Version with less space and time
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        pathSum(res, path, root, sum);
        return res;
    }
    
    void pathSum(vector<vector<int>>& res, vector<int>& path, TreeNode *root, int sum) {
        path.push_back(root->val);
        if (!root->left && !root->right && root->val==sum) res.push_back(path);
        if (root->left) pathSum(res, path, root->left, sum-root->val);
        if (root->right) pathSum(res, path, root->right, sum-root->val);
        path.pop_back();
        return;
    }
};