// Merge Sorted Array
/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/


// Forward Version, extra space
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *C = new int[m+n];
        int p = 0, q = 0;
        for (int i=0; i<m+n; ++i) {
            if (p<m && q<n) C[i] = A[p]<=B[q] ? A[p++]: B[q++];
            else if (p == m) C[i] = B[q++];
            else if (q == n) C[i] = A[p++];
        }
        for (int i=0; i<m+n; ++i) A[i] = C[i];
        delete[] C;
    }
};

// Backward Version, constant space
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int p = m - 1, q = n - 1;
        for (int i=m+n-1; i>=0; --i) {
            if (p>=0 && q>=0) A[i] = A[p]>=B[q]? A[p--]:B[q--];
            else if (p < 0) A[i] = B[q--];
            else if (q < 0) A[i] = A[p--];
        }
    }
};