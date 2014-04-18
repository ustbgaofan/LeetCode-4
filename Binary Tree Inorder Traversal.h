// Binary Tree Inorder Traversal 
/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
 
// Recursive Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    void inorderTraversal(TreeNode *root, vector<int> &res) {
        if (!root) return;
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }
};

// Iterative Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            res.push_back(root->val);   
            stk.pop();
            root = root->right;
        }
        return res;
    }
};

// Morris Traversal, time complexity O(n), space complexity O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return res;
    }
};