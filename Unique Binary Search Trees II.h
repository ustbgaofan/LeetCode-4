// Unique Binary Search Trees II
/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
 
// Recursive Version, passed!
class Solution {
public:
    vector<TreeNode *> generateTrees(int begin, int end) {
        vector<TreeNode *> res;
        if (begin > end) {
            res.push_back(NULL);
            return res;
        }
        for (int i=begin; i<=end; ++i) {
            vector<TreeNode *> lefts = generateTrees(begin, i-1);
            vector<TreeNode *> rights = generateTrees(i+1, end);
            for (int p=0; p<lefts.size(); ++p) {
                for (int q=0; q<rights.size(); ++q) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[p];
                    root->right = rights[q];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
};

// Top-down Dynamic Programming Version
class Solution {
public:
    vector<TreeNode *> generateTrees(int begin, int end, vector<vector<vector<TreeNode *>>> &mem) {
        vector<TreeNode *> res;
        if (begin > end) {
            res.push_back(NULL);
            return res;
        }
        if (!mem[begin-1][end-1].empty()) return mem[begin-1][end-1];
        for (int i=begin; i<=end; ++i) {
            vector<TreeNode *> lefts = generateTrees(begin, i-1, mem);
            vector<TreeNode *> rights = generateTrees(i+1, end, mem);
            for (int p=0; p<lefts.size(); ++p) {
                for (int q=0; q<rights.size(); ++q) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[p];
                    root->right = rights[q];
                    res.push_back(root);
                }
            }
        }
        return mem[begin-1][end-1] = res;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<vector<TreeNode *>>> mem(n, vector<vector<TreeNode *>>(n, vector<TreeNode *>()));
        return generateTrees(1, n, mem);
    }
};

// Bottom-up Dynamic Programming Version
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<vector<TreeNode *>>> mem(n+2, vector<vector<TreeNode *>>(n+2, vector<TreeNode *>()));
        for (int i=n+1; i>0; --i) {
            mem[i][i-1].push_back(NULL);
            for (int j=i; j<=n; ++j) {
                for (int p=i-1, q=i+1; p<j; ++p, ++q) {
                    for (int t=0; t<mem[i][p].size(); ++t) {
                        for (int k=0; k<mem[q][j].size(); ++k) {
                            TreeNode *node = new TreeNode(p+1);
                            node->left = mem[i][p][t];
                            node->right = mem[q][j][k];
                            mem[i][j].push_back(node);
                        }
                    }
                }
            }
        }
        return mem[1][n];
    }
};
