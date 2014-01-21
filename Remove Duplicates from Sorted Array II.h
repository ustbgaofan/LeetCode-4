// Remove Duplicates from Sorted Array II 
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/


// Inexperienced Version
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int i = 0;
        bool flag = false;
        for (int j=1; j<n; ++j) {
            if (A[i] != A[j]) {
                A[++i] = A[j];
                flag = false;
            } else if (A[i]==A[j] && !flag) {
                A[++i] = A[j];
                flag = true;
            }
        }
        return i+1;
    }
};

// Experienced Version
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int i = 1;
        for (int j=2; j<n; ++j) {
            if (A[j]!=A[i] || A[j]!=A[i-1]) A[++i] = A[j];
        }
        return i+1;
    }
};