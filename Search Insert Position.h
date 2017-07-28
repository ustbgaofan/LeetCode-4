// Search Insert Position
/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

// Not recommend, difficult to debug, time O(logn), space O(1)
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin = 0, end = n - 1, mid;
        while (begin <= end) {
            mid = (begin + end)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) begin = mid + 1;
            else end = mid - 1;
        }
	return begin;
    }
};

// time O(logn), space O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, res = 0;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (target > nums[m]) res = l = m + 1;
            if (target < nums[m]) res = m, r = m - 1;
            if (target == nums[m]) return m;
        }
        return res;
    }
};
