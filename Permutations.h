// Permutations 
/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

// DFS, time O(n!n), space O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(nums, res, path);
        return res;
    }
    
    void DFS(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (find(path.begin(), path.end(), nums[i]) != path.end()) continue;
            path.push_back(nums[i]);
            DFS(nums, res, path);
            path.pop_back();
        }
    }
};

// DFS, time O(n!), space O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            if (visited[i]) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            DFS(nums, res, path, visited);
            visited[i] = false;
            path.pop_back();
        }
    }
};
