// Search in Rotated Sorted Array II 
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/


// (not suggested) 1st Version, time complexity O(log(n))~O(n), space complexity O(1) 
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
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) return true;
            if (nums[m] < nums[r]) { // right side is sorted
                if (target>nums[m] && target<=nums[r]) l = m + 1;
                else r = m - 1;
            } else if (nums[m] > nums[r]) {  // left side is sorted
                if (target>=nums[l] && target<nums[m]) r = m - 1;
                else l = m + 1;
            } else {
                --r;
            }
        }
        return false;
    }
};
