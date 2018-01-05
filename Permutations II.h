// Permutations II
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

// DFS, time O(n!), space O(n)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        DFS(nums, res, path, visited);
        return res;
    }
    
    void DFS(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& visited) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1])) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            DFS(nums, res, path, visited);
            visited[i] = false;
            path.pop_back();
        }
    }
};
