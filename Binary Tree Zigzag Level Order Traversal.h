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
        int level = 0;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            vector<int> t;
            int k = q.size();
            for (int i=0; i<k; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                t.push_back(node->val);
            }
            if (level%2 == 1) reverse(t.begin(), t.end());
            ++level;
            res.push_back(t);
        }
        return res;
    }
};
