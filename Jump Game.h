// Jump Game
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

// Greedy, time O(n), space O(1) 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;
        for (int i=0, reach=0; i<nums.size() && i<=reach; ++i) {
            reach = max(reach, i+nums[i]);
            if (reach >= nums.size()-1) return true;
        }
        return false;
    }
};
