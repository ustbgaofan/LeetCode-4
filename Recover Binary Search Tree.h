// Recover Binary Search Tree
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
 
// Vector, time O(n), space O(n)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        int i = 0, j = v.size() - 1;
        for (; i<v.size()-1 && v[i]->val<v[i+1]->val; ++i);
        for (; j>0 && v[j]->val>v[j-1]->val; --j);
        swap(v[i]->val, v[j]->val);
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
};

// Two-pointers, time O(n), space O(h)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev1 = nullptr, *prev2 = nullptr;
        swap(inorder(root, prev1)->val, rinorder(root, prev2)->val);
    }
    
    TreeNode* inorder(TreeNode* root, TreeNode*& prev) {
        if (!root) return nullptr;
        TreeNode* res = inorder(root->left, prev);
        if (res) return res;
        if (prev && root->val<prev->val) return prev;
        return inorder(root->right, prev=root);
    }
    
    TreeNode* rinorder(TreeNode* root, TreeNode*& prev) {
        if (!root) return nullptr;
        TreeNode* res = rinorder(root->right, prev);
        if (res) return res;
        if (prev && root->val>prev->val) return prev;
        return rinorder(root->left, prev=root);
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
