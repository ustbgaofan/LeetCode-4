// Trapping Rain Water 
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

// Brute Force, time O(n^2), space O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size(), res = 0; 
        for (int i=0; i<N; ++i) {
            int left = 0, right = 0;
            for (int j=i; j>=0; --j) left = max(left, height[j]);
            for (int j=i; j<N; ++j) right = max(right, height[j]);
            res += min(left, right) - height[i];
        }
        return res;
    }
};

// Dynamic Programming, time O(n), space O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int N = height.size(), res = 0;
        vector<int> lmax(N, height[0]), rmax(N, height.back());
        for (int i=1; i<N; ++i) lmax[i] = max(height[i], lmax[i-1]); 
        for (int i=N-2; i>=0; --i) rmax[i] = max(height[i], rmax[i+1]);
        for (int i=0; i<N; ++i) res += min(lmax[i], rmax[i]) - height[i];
        return res;
    }
};

// Constant Space Dynamic Programming, time O(n), space O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size(), res = 0, maxPos = 0;
        for (int i=1; i<N; ++i) {
            if (height[i] > height[maxPos]) maxPos = i;
        }
        for (int i=1, l=0; i<maxPos; ++i) {
            l = max(l, height[i-1]);
            res += max(l-height[i], 0);
        }
        for (int i=N-2, r=0; i>maxPos; --i) {
            r = max(r, height[i+1]);
            res += max(r-height[i], 0);
        }
        return res;
    }
};
