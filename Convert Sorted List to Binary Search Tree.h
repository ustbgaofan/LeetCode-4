// Convert Sorted List to Binary Search Tree
/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
 
// Top-down Version (preorder), time O(nlogn), space O(h)
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head, int l, int r) {
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        ListNode *cur = head;
        int c = m - l;
        while (c-- > 0) cur = cur->next;
        TreeNode *root = new TreeNode(cur->val);
        root->left = sortedListToBST(head, l, m-1);
        root->right = sortedListToBST(cur->next, m+1, r);
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        int N = 0;
        for (ListNode *cur=head; cur; cur=cur->next) ++N;
        return sortedListToBST(head, 0, N-1);
    }
};

// Bottom-up Version (inorder), time O(n), space O(h)
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *&cur, int l, int r) {
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode *left = sortedListToBST(cur, l, m-1);
        TreeNode *root = new TreeNode(cur->val);
        root->left = left;
        root->right = sortedListToBST(cur=cur->next, m+1, r);
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        int N = 0;
        for (ListNode *cur=head; cur; cur=cur->next) ++N;
        ListNode *cur = head;
        return sortedListToBST(cur, 0, N-1);
    }
};
