// Combination Sum
/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

// time O(2^n), space O(target/min)
// C(n,0)+C(n,1)+...+C(n,n)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(candidates, 0, target, path, res);
        return res;
    }
    
    void DFS(const vector<int>& nums, int i, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target <= 0) {
            if (target == 0) res.push_back(path);
            return;
        }
        for (int j=i; j<nums.size(); ++j) {
            path.push_back(nums[j]);
            DFS(nums, j, target-nums[j], path, res);
            path.pop_back();
        }
    }
};
