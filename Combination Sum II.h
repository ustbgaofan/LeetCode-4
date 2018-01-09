// Combination Sum II
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/


// Naive Version, using set to avoid duplicates
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        DFS(candidates, 0, target, path, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
    
    void DFS(const vector<int>& num, int i, int target, vector<int>& path, set<vector<int>>& res) {
        if (target <= 0) {
            if (target == 0) res.insert(path);
            return;
        }
        for (int j=i; j<num.size(); ++j) {
            path.push_back(num[j]);
            DFS(num, j+1, target-num[j], path, res);
            path.pop_back();
        }
    }
};

// Advanced Version, avoiding duplicates without set, time O(2^n), space O(target/min)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());  // with duplicates
        DFS(candidates, 0, target, path, res);
        return res;
    }
    
    void DFS(const vector<int>& nums, int i, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target <= 0) {
            if (target == 0) res.push_back(path);
            return;
        }
        for (int j=i; j<nums.size(); ++j) {
            if (j>i && nums[j]==nums[j-1]) continue;  // with duplicates 
            path.push_back(nums[j]);
            DFS(nums, j+1, target-nums[j], path, res);  // Each number in C may only be used once in the combination.
            path.pop_back();
        }
    }
};
