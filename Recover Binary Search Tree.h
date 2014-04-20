// Recover Binary Search Tree
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
 
// Vector Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    void inorderTraversal(TreeNode *root, vector<TreeNode *> &v) {
        if (!root) return;
        inorderTraversal(root->left, v);
        v.push_back(root);
        inorderTraversal(root->right, v);
    }
    
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> v;
        inorderTraversal(root, v);
        int i = 0;
        for (; i<v.size()-1 && v[i]->val<v[i+1]->val; ++i);
        int j = v.size() - 1;
        for (; j>0 && v[j]->val>v[j-1]->val; --j);
        swap(v[i]->val, v[j]->val);
    }
};

// Two-pointers Version, time complexity O(n), space complexity O(h)
class Solution {
public:
    TreeNode *inorderTraversal(TreeNode *&prev, TreeNode *cur) {
        if (!cur) return NULL;
        TreeNode *res = inorderTraversal(prev, cur->left);
        if (res) return res;
        else if (prev && prev->val>cur->val) return prev; 
        else return inorderTraversal(prev=cur, cur->right);
    }
    
    TreeNode *rinorderTraversal(TreeNode *&prev, TreeNode *cur) {
        if (!cur) return NULL;
        TreeNode *res = rinorderTraversal(prev, cur->right);
        if (res) return res;
        else if (prev && prev->val<cur->val) return prev; 
        else return rinorderTraversal(prev=cur, cur->left);
    }
    
    void recoverTree(TreeNode *root) {
        TreeNode *prev1 = NULL, *prev2 = NULL;
        swap(inorderTraversal(prev1, root)->val, rinorderTraversal(prev2, root)->val);
    }
};

// Morris Traversal, time complexity O(n), space complexity O(1)
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        while (root) {
            if (!root->left) {
                if (prev && prev->val>root->val) {
                    if (!first) first = prev;
                    second = root;
                }
                prev = root;
                root= root->right;
            } else {
                TreeNode *tmpPrev = root->left;
                while (tmpPrev->right && tmpPrev->right!=root) {
                    tmpPrev = tmpPrev->right;
                }
                if (!tmpPrev->right) {
                    tmpPrev->right = root;
                    root = root->left;
                } else {
                    if (prev && prev->val>root->val) {
                        if (!first) first = prev;
                        second = root;
                    }
                    prev = root;
                    tmpPrev->right = NULL;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};