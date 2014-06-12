// Binary Tree Preorder Traversal
/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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

// Recursive Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    void preorderTraversal(TreeNode *root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
};

// Iterative Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                res.push_back(root->val);   
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};

// Morris Traversal, time complexity O(n), space complexity O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        while (root) {
            if (!root->left) {
                res.push_back(root->val);
                root = root->right;
            } else {
                TreeNode *prev = root->left;
                while (prev->right && prev->right!=root) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    res.push_back(root->val);
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        return res;
    }
};