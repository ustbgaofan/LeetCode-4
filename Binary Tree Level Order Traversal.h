// Binary Tree Level Order Traversal
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
 
// BFS, time O(n), space O(n) 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int k = q.size();
            res.push_back({});
            for (int i=0; i<k; ++i) {
                TreeNode* f = q.front();
                q.pop();
                res.back().push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
        }
        return res;
    }
};

// DFS, time O(n), space O(h)  
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root, res, 0);
        return res;
    }
    
    void DFS(TreeNode* root, vector<vector<int>>& res, int depth) {
        if (!root) return;
        if (depth == res.size()) res.push_back({});
        res[depth].push_back(root->val);
        DFS(root->left, res, depth+1);
        DFS(root->right, res, depth+1);
    }
};
