// Search for a Range 
/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

// Naive Version, time complexity: worst case O(n) 
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r)/2;
            if (target < A[m]) {
                r = m - 1; 
            } else if (target > A[m]) {
                l = m + 1;
            } else {
                int i = m - 1;
                for (; i>=0 && A[i]==target; --i);
                res[0] = i + 1;
                i = m + 1;
                for (; i<n && A[i]==target; ++i);
                res[1] = i - 1;
                return res;
            }
        }
        return res;
    }
};

// Advanced Version, time complexity: O(log(n)) 
class Solution {
public:
    int searchLowerBound(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r)/2;
            if (target <= A[m]) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
    
    int searchUpperBound(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r)/2;
            if (target >= A[m]) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int l = searchLowerBound(A, n, target);
        int r = searchUpperBound(A, n, target);
        if (l <= r) res[0] = l, res[1] = r;
        return res;
    }
};