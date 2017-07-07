// 4Sum 
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/


// Transform 4Sum to 3Sum. time O(n^3), space O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> res;
        for (int i=0; i<N; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<N; ++j) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int l = j + 1, r = N - 1;
                while (l < r) {
                    int s = nums[l] + nums[r] + nums[i] + nums[j]; 
                    if (s == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do ++l; while (l<r && nums[l]==nums[l-1]);
                        do --r; while (r>l && nums[r]==nums[r+1]);
                    }
                    if (s < target) ++l;
                    if (s > target) --r;
                }
            }
        }
        return res;
    }
};
