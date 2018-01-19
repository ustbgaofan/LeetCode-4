// Binary Tree Zigzag Level Order Traversal
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Two Stacks, time O(n), space O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> stk[2];
        int cur = 0;
        if (root) stk[cur].push(root);
        while (!stk[cur].empty()) {
            vector<int> line;
            while (!stk[cur].empty()) {
                TreeNode *node = stk[cur].top();
                stk[cur].pop();
                if (cur == 0) {
                    if (node->left) stk[1].push(node->left);
                    if (node->right) stk[1].push(node->right);
                } else {
                    if (node->right) stk[0].push(node->right);
                    if (node->left) stk[0].push(node->left);
                }
                line.push_back(node->val);
            }
            res.push_back(line);
            cur = (++cur) % 2;
        }
        return res;
    }
};

// Queue + Reverse, time O(n), space O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int cur = 0;
        queue<TreeNode*> q;
        if (root) q.push(root);
        q.push(nullptr);
        while (q.front()) {
            vector<int> line;
            while (q.front()) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                line.push_back(node->val);
            }
            q.pop();
            q.push(nullptr);
            if (cur == 1) reverse(line.begin(), line.end());
            cur = (++cur) % 2;
            res.push_back(line);
        }
        return res;
    }
};
