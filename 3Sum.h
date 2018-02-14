// 3Sum
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


// 3Sum --> 2Sum. time O(n^2), space O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i=0; i<N; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int l = i + 1, r = N - 1;
            while (l < r) {
                if (nums[l]+nums[r] == -nums[i]) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    do ++l; while (l<r && nums[l]==nums[l-1]);
                    do --r; while (r>l && nums[r]==nums[r+1]);
                }
                else if (nums[l]+nums[r] < -nums[i]) ++l;
                else --r;
            }
        }
        return res;
    }
};
