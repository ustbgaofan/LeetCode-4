// Subsets 
/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

// Recursive, time O(2^n), space O(n)
// every element has 2 choices
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(nums, res, path, 0);
        return res;
    }
    
    void DFS(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int i) {
        if (i == nums.size()) {
            res.push_back(path);
            return;
        }
        DFS(nums, res, path, i+1);
        path.push_back(nums[i]);
        DFS(nums, res, path, i+1);
        path.pop_back();
    }
};

// Iterative, time O(2^n), space O(1)
// push nums[i] at the end
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        for (int i=0; i<nums.size(); ++i) {
            int k = res.size();
            for (int j=0; j<k; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
