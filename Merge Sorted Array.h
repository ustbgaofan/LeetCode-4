// Merge Sorted Array
/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/


// Forward, time O(m+n), space O(m)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(nums1.begin(), nums1.begin()+m);
        int i = 0, j = 0, k = 0;
        while (i<m && j<n) {
            nums1[k++] = (tmp[i] <= nums2[j]) ? tmp[i++]: nums2[j++];
        }
        while (i < m) nums1[k++] = tmp[i++];
        while (j < n) nums1[k++] = nums2[j++];
    }
};

// Backward, time O(m+n), space O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i>=0 && j>=0) {
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
        while (i>=0) nums1[k--] = nums1[i--];
        while (j>=0) nums1[k--] = nums2[j--];
    }
};
