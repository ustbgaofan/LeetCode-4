// First Missing Positive 
/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


// Naive Version, time complexity O(nlog(n)), space complexity O(1)
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        sort(A, A+n);
        int j = 1;
        for (int i=0; i<n; ++i) {
            if (A[i] > 0) {
                if (A[i] > j) return j;
                if (A[i] == j) ++j;
            }
        }
        return j;
    }
};

// Hash-based Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_set<int> hash(A, A+n);
        for (int i=1; i<=n; ++i) {
            if (hash.find(i) == hash.end()) return i;
        }
        return n+1;
    }
};

// Advanced Version, time complexity O(n), space complexity O(1)
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i=0; i<n; ) {
            if (A[i]>=1 && A[i]<=n && A[i]!=i+1 && A[A[i]-1]!=A[i]) swap(A[i], A[A[i]-1]);
            else ++i;
        }
        for (int i=0; i<n; ++i) {
            if (A[i] != i+1) return i+1;
        }
        return n+1;
    }
};