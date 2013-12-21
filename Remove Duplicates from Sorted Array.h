// Remove Duplicates from Sorted Array
/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/


// Inexperienced Version
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return n;
        int j = 0;
        for (int i=1; i<n; ++i) {
            if (A[j] != A[i]) A[++j] = A[i];
            else {
                while (A[i]==A[j] && i<n-1) ++i;
                if (i==n-1 && A[i]==A[j]) break;
                else A[++j] = A[i];
            }
        }
        return j+1;
    }
};

// Experienced version
// It hides the else logic above in the for loop 
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return n;
        int j = 0;
        for (int i=1; i<n; ++i)
            if (A[i] != A[j]) A[++j] = A[i];
        return j+1;
    }
};

// Experienced version
// A[i] != A[j] <==> A[i] != A[i-1]
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return n;
        int j = 0;
        for (int i=1; i<n; ++i)
            if (A[i] != A[i-1]) A[++j] = A[i];
        return j+1;
    }
};