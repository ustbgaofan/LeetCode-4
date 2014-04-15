// Sort Colors
/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/


// Insertion Sort, time complexity O(n)~O(n^2), space complexity O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        for (int i=1; i<n; ++i) {
            int t = A[i], j = i;
            for (; j>0 && t<A[j-1]; --j) A[j] = A[j-1];
            A[j] = t;
        }
    }
};

// Selection Sort, time complexity O(n^2), space complexity O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        for (int i=0; i<n; ++i) {
            int k = i;
            for (int j=i+1; j<n; ++j) {
                if (A[k] > A[j]) k = j;
            }
            swap(A[i], A[k]);
        }
    }
};

// Quick Sort, time complexity O(nlog(n))~O(n^2), space complexity O(log(n))~O(n)
class Solution {
public:
    void sortColors(int A[], int l, int r) {
        if (l >= r) return;
        swap(A[l], A[l+rand()%(r-l+1)]);
        int m = l;
        for (int i=l+1; i<=r; ++i) {
            if (A[i] < A[l]) swap(A[i], A[++m]);
        }
        swap(A[m], A[l]);
        sortColors(A, l, m-1);
        sortColors(A, m+1, r);
    }
    
    void sortColors(int A[], int n) {
        sortColors(A, 0, n-1);
    }
};

// Merge Sort, time complexity O(nlog(n)), space complexity O(n)
class Solution {
public:
    void sortColors(int A[], int l, int r) {
        if (l >= r) return;
        int m = (l + r) >> 1;
        sortColors(A, l, m);
        sortColors(A, m+1, r);
        vector<int> B(A+l, A+r+1);
        int i = l, j = m + 1, k = l;
        while (i<=m && j<=r) A[k++] = B[i-l]<=B[j-l]? B[(i++)-l]: B[(j++)-l];
        while (i <= m) A[k++] = B[(i++)-l];
        while (j <= r) A[k++] = B[(j++)-l];
    }
    
    void sortColors(int A[], int n) {
        sortColors(A, 0, n-1);
    }
};

// Heap Sort, time complexity O(nlog(n)), space complexity O(1)
class Solution {
public:
    void siftDown(int A[], int begin, int end) {
        for (int i=begin, c; (c=(i<<1)+1)<end; i=c) {
            if (c+1<end && A[c] < A[c+1]) ++c;
            if (A[i] >= A[c]) break;
            swap(A[i], A[c]);
        }
    }
    
    void sortColors(int A[], int n) {
        for (int i=(n-2)/2; i>=0; --i) siftDown(A, i, n);
        for (int i=n-1; i>0; --i) {
            swap(A[0], A[i]);
            siftDown(A, 0, i);
        }
    }
};

// Counting Sort, general, time complexity O(n), space complexity O(n)
class Solution {
public:
    void sortColors(int A[], int n) {
        int B[3] = {0, 0, 0};
        for (int i=0; i<n; ++i) ++B[A[i]];
        for (int i=1; i<3; ++i) B[i] += B[i-1];
        vector<int> C(A, A+n);
        for (int i=n-1; i>=0; --i) A[--B[C[i]]] = C[i];
    }
};

// Counting Sort, specific, time complexity O(n), space complexity O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        int B[3] = {0, 0, 0};
        for (int i=0; i<n; ++i) ++B[A[i]];
        for (int i=0, j=0; i<3; ++i) {
            while (B[i]--) A[j++] = i;
        }
    }
};