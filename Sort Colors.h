// Sort Colors
/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

// Counting Sort, two-pass, time O(n), space O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cc(3, 0);
        for (int i : nums) ++cc[i];
        for (int i=0, j=0, t=0; i<cc.size(); ++i, t+=j) {
            for (j=0; j<cc[i]; ++j) nums[t+j] = i;
        }
    }
};

// Counting Sort + Swap, one-pass, time O(n), space O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        for (int i=0, j=N-1, k=0; k<=j; ++k) {
            if (nums[k] == 0) swap(nums[k], nums[i++]);
            if (nums[k] == 2) swap(nums[k--], nums[j--]); 
        } 
    }
};
