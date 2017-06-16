// 3Sum
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/


// Transform 3Sum to 2Sum. Be careful of the meaning of duplicate triplets.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
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
