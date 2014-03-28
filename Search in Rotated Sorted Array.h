// Search in Rotated Sorted Array
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/


// time complexity O(log(n))
class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target < A[m]) {
                if (A[l]>A[r] && A[m]>A[r] && target<A[l]) l = m + 1;
                else r = m - 1;
            } else if (target > A[m]) {
                if (A[l]>A[r] && A[m]<A[r] && target>A[r]) r = m - 1;             
                else l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};