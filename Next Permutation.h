// Next Permutation
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/


// time O(n), space O(1)
// https://leetcode.com/problems/next-permutation/solution/
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int N = nums.size(), i = N - 1;
        for (; i>=1 && nums[i]<=nums[i-1]; --i);
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = i;
        for (; j<N && nums[i-1]<nums[j]; ++j);
        swap(nums[j-1], nums[i-1]);
        reverse(nums.begin()+i, nums.end());
    }
};
