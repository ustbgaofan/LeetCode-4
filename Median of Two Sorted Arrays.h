// Median of Two Sorted Arrays
/*
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/


// Naive Version, time complexity O(m+n), space complexity O(1)
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        assert(m!=0 || n!=0);
        int t1 = INT_MIN, t2 = INT_MIN, len = ((m+n)>>1) + 1;
        for (int i=0, j=0, p=0; p<len; ++p) {
            t1 = t2;
            if (i == m) {
                t2 = B[j++];
                continue;
            }
            if (j == n) {
                t2 = A[i++];
                continue;
            }
            if (A[i] <= B[j]) t2 = A[i++];
            else t2 = B[j++];
        }
        return (m+n)&0x1? t2: (t1+t2)/2.0;
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