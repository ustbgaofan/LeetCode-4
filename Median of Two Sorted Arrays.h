// Median of Two Sorted Arrays
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

// time O(m+n), space O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size(), N = nums2.size(), len = (M+N)/2, a, b;
        for (int i=0, j=0, p=0; p<=len; ++p) {
            a = b;
            if (i == M) {
                b = nums2[j++];
            } else if (j == N) {
                b = nums1[i++];
            } else if (nums1[i] <= nums2[j]) {
                b = nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                b = nums2[j++];
            }
        }
        return (M+N)%2? b: (a+b)/2.0;
    }
};

// Hard!!!, time O(log(m+n)), space O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size(), N = nums2.size();
        int l = (M+N+1) / 2, r = (M+N+2) / 2;
        return (findKth(nums1, 0, nums2, 0, l) + findKth(nums1, 0, nums2, 0, r)) / 2.0;
    }
    
    int findKth(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
        int M = nums1.size(), N = nums2.size();
        if (s1 == M) return nums2[s2+k-1];
        if (s2 == N) return nums1[s1+k-1];
        if (k == 1) return min(nums1[s1], nums2[s2]);
        
        int mid1 = nums1[min(M,s1+k/2) - 1], mid2 = nums2[min(N,s2+k/2) - 1];
        if (mid1 < mid2) {
            return findKth(nums1, s1+min(M,k/2), nums2, s2, k-min(M,k/2));
        } else {
            return findKth(nums1, s1, nums2, s2+min(N,k/2), k-min(N,k/2));
        }
    }
};
