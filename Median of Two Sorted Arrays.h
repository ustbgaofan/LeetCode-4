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

// Advanced Version, time complexity O(log(m+n)), space complexity O(log(m+n))
class Solution {
public:
    int findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKth(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);
        int l = min(k>>1, m), r = k - l;
        if (A[l-1] < B[r-1]) return findKth(A+l, m-l, B, r, k-l);
        if (A[l-1] > B[r-1]) return findKth(A, l, B+r, n-r, k-r);
        return A[l-1];
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        assert(m!=0 || n!=0);
        int len = m + n, half = (m + n) >> 1;
        if (len & 0x1) return findKth(A, m, B, n, half+1);
        else return (findKth(A, m, B, n, half) + findKth(A, m, B, n, half+1)) / 2.0;
    }
};
