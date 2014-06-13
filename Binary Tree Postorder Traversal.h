// Binary Tree Postorder Traversal
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    void postorderTraversal(TreeNode *root, vector<int> &res) {
        if (!root) return;
        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }
};

// Iterative Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;               
        TreeNode *prev = NULL; 
        if (root) stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            if (!root->left && !root->right || prev && (prev==root->left || prev==root->right)) {
                res.push_back(root->val);
                stk.pop();
                prev = root;
            } else {
                if (root->right) stk.push(root->right);
                if (root->left) stk.push(root->left);
            }
        }
        return res;
    }
};

// Morris Traversal, time complexity O(n), space complexity O(1)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode dummy(0);
        dummy.left = root;
        root = &dummy;
        while (root) {
            if (!root->left) {
                root = root->right;
            } else {
                TreeNode *prev = root->left;
                while (prev->right && prev->right!=root) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = root;
                    root = root->left;
                } else {
                    int l = res.size();
                    prev = root->left;
                    while (prev->right != root) {
                        res.push_back(prev->val);
                        prev = prev->right;
                    }
                    res.push_back(prev->val);
                    reverse(res.begin()+l, res.end());
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        return res;
    }
};