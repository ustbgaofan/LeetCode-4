// Trapping Rain Water 
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/


// Two-array Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3) return 0;
        vector<int> rmax(n, 0);
        for (int i=n-2; i>=1; --i) rmax[i] = max(rmax[i+1], A[i+1]);
        vector<int> lmax(n-1, 0);
        for (int i=1; i<=n-2; ++i) lmax[i] = max(lmax[i-1], A[i-1]);
        int res = 0;
        for (int i=1; i<n-1; ++i) res += max(0, min(lmax[i], rmax[i]) - A[i]);
        return res;
    }
};

// One-array Version, time complexity O(n), space complexity O(n) with a smaller constant
class Solution {
public:
    int trap(int A[], int n) {
        vector<int> rmax(n, 0);
        for (int i=n-2; i>=1; --i) rmax[i] = max(rmax[i+1], A[i+1]);
        int res = 0;
        for (int i=1, lmax=0; i<n-1; ++i) {
            lmax = max(lmax, A[i-1]);
            res += max(0, min(rmax[i], lmax) - A[i]);
        }
        return res;
    }
};

// No-array Version, time complexity O(n), space complexity O(1)
class Solution {
public:
    int trap(int A[], int n) {
        int maxPos = 0;
        for (int i=1; i<n; ++i) {
            if (A[maxPos] < A[i]) maxPos = i; 
        }
        int res = 0;
        for (int i=1, h=0; i<maxPos; ++i) {
            h = max(h, A[i-1]);
            res += max(h-A[i], 0);
        }
        for (int i=n-2, h=0; i>maxPos; --i) {
            h = max(h, A[i+1]);
            res += max(h-A[i], 0);
        }
        return res;
    }
};