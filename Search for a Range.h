// Search for a Range 
/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

// Naive Binary Search, time O(n), space O(1) 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (target > nums[m]) l = m + 1;
            if (target < nums[m]) r = m - 1;
            if (target == nums[m]) {
                for (l=m-1; l>=0 && nums[l]==target; --l);
                for (r=m+1; r<=nums.size()-1 && nums[r]==target; ++r);
                return vector<int>({++l, --r});
            }
        }
        return vector<int>({-1, -1});
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
