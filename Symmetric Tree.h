// Symmetric Tree
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
 
// Recursive Version
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

// Iterative Version, Null is disallowed in queue, code is relatvie long
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            if (left->val != right->val) return false;
            if (!left->left&&right->right || left->left&&!right->right) return false;
            if (!left->right&&right->left || left->right&&!right->left) return false;
            if (left->left && right->right) {
                q.push(left->left);
                q.push(right->right);
            }
            if (left->right && right->left) {
                q.push(left->right);
                q.push(right->left);
            }
        }
        return true;
    }
};

// Iterative Version, Null is allowed in queue, code is relatvie short
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};