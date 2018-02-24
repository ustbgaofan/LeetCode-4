// Search for a Range 
/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

// Linear Search, time O(n), space O(1) 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == target) {
                if (res[0] == -1) res[0] = i;
                res[1] = i;
            }
        }
        return res;
    }
};

// Binary Search, time O(n), space O(1) 
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
                for (r=m+1; r<nums.size() && nums[r]==target; ++r);
                return {++l, --r};
            }
        }
        return {-1, -1};
    }
};

// Lower & Upper Bound, time O(logn), space O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);  // first elem >= target
        if (l==nums.end() || *l!=target) return {-1, -1};
        auto r = upper_bound(nums.begin(), nums.end(), target);  // first elem > target
        return {l-nums.begin(), r-nums.begin()-1};
    }
};

// Lower & Upper Bound, time O(logn), space O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = searchBound(nums, target, true);
        int r = searchBound(nums, target, false);
        if (l!=-1 && r!=-1) return {l, r};
        return {-1, -1};
    }
    
    int searchBound(const vector<int>& nums, int target, bool lower) {
        int l = 0, r = nums.size() - 1, res = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (target > nums[m]) l = m + 1;
            if (target < nums[m]) r = m - 1;
            if (target == nums[m]) {
                res = m;
                lower? r=m-1: l=m+1;
            }
        }
        return res;
    }
};
