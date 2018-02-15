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
 
// BFS, time complexity O(n), space complexity O(n) 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> res(1);
        while (q.size() > 1) {
            TreeNode* f = q.front();
            q.pop();
            if (!f) {
                q.push(nullptr);
                res.push_back({});
            } else {
                res.back().push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
        }
        return res;
    }
};

// DFS, time complexity O(n), space complexity O(h)  
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
