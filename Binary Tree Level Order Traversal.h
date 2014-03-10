// Binary Tree Level Order Traversal
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
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
 
// BFS, time complexity O(n), space complexity O(n) 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(NULL);
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node && !q.empty()) {
                q.push(NULL);
                res.push_back(vector<int>());
            } else if (node) {
                res.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

// DFS, time complexity O(n), space complexity O(h)  
class Solution {
public:
    void levelOrder(vector<vector<int>> &res, TreeNode *root, int depth) {
        if (!root) return;
        if (res.size() <= depth) res.push_back(vector<int>());
        res[depth].push_back(root->val);
        levelOrder(res, root->left, depth+1);
        levelOrder(res, root->right, depth+1);
    }
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        levelOrder(res, root, 0);
        return res;
    }
};