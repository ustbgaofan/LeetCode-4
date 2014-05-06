// Search in Rotated Sorted Array II 
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/


// 1st Version, time complexity O(log(n))~O(n), space complexity O(1) 
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target < A[m]) {
                if (A[l]>=A[r] && A[m]>=A[r] && target<A[l]) {
                    if (A[m] == A[r]) --r;
                    else l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (target > A[m]) {
                if (A[l]>=A[r] && A[m]<=A[r] && target>A[r]) {
                    if (A[m] == A[r]) --r;
                    else r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                return true;
            }
        }
        return false;
    }
};

// 2nd Version, time complexity O(log(n))~O(n), space complexity O(1) 
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target == A[m]) return true; 
            if (A[m] > A[l]) { 
                if (target>=A[l] && target<A[m]) r = m - 1;
                else l = m + 1;
            } else if (A[m] < A[l]) { 
                if (target<=A[r] && target>A[m]) l = m + 1;
                else r = m - 1;
            } else {
                ++l;
            }
        }
        return false;
    }
};