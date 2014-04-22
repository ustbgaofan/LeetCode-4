// Convert Sorted List to Binary Search Tree
/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
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
 
// Top-down Version (preorder), time complexity O(nlog(n)), space complexity O(h)
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head, int l, int r) {
        if (l > r) return NULL;
        int m = (l + r) >> 1;
        ListNode *cur = head;
        int c = m - l;
        while (c-- > 0) cur = cur->next;
        TreeNode *root = new TreeNode(cur->val);
        root->left = sortedListToBST(head, l, m-1);
        root->right = sortedListToBST(cur->next, m+1, r);
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        for (ListNode *cur=head; cur; cur=cur->next) ++n;
        return sortedListToBST(head, 0, n-1);
    }
};

// Bottom-up Version (inorder), time complexity O(n), space complexity O(h)
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *&cur, int l, int r) {
        if (l > r) return NULL;
        int m = (l + r) >> 1;
        TreeNode *left = sortedListToBST(cur, l, m-1);
        TreeNode *root = new TreeNode(cur->val);
        root->left = left;
        root->right = sortedListToBST(cur=cur->next, m+1, r);
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        for (ListNode *cur=head; cur; cur=cur->next) ++n;
        ListNode *cur = head;
        return sortedListToBST(cur, 0, n-1);
    }
};