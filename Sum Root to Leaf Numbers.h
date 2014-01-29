// Sum Root to Leaf Numbers
/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
 
 // Recursive Version, Depth First Search
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
    
    void sumNumbers(TreeNode *root, int val, int &sum) {
        if (!root) return;
        val = val*10 + root->val;
        if (!root->left && !root->right) sum += val;
        sumNumbers(root->left, val, sum);
        sumNumbers(root->right, val, sum);
    }
};

// Iterative Version, Breadth First Search
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        int sum = 0;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            int val = p.second*10 + p.first->val;
            if (!p.first->left && !p.first->right) 
                sum += val;
            if (p.first->left) 
                q.push(make_pair(p.first->left, val));
            if (p.first->right) 
                q.push(make_pair(p.first->right, val));
        }
        return sum;
    }
};