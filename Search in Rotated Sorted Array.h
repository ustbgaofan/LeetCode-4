// Search in Rotated Sorted Array
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/


// (Not suggested) time O(logn), space O(1)
// case analysis:
// t<[m]: 1. [l]>[r] 1.1 [m]>[r] 1.2 [m]<[r]  2. [l]<[r]
// t>[m]: 1. [l]>[r] 1.1 [m]>[r] 1.2 [m]<[r]  2. [l]<[r]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] > target) {
                if (nums[l]>nums[r] && nums[m]>nums[r] && target<=nums[r]) l = m + 1;
                else r = m - 1;
            } else if (nums[m] < target) {
                if (nums[l]>nums[r] && nums[m]<nums[r] && target>=nums[l]) r = m - 1;
                else l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};

// time O(logn), space O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) return m;
            if (nums[m] < nums[r]) { // right side is sorted
                if (target>nums[m] && target<=nums[r]) l = m + 1;
                else r = m - 1;
            } else {  // left side is sorted
                if (target>=nums[l] && target<nums[m]) r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
};
