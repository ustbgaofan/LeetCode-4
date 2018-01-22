// Subsets 
/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

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

// Recursive, every element has 2 choices
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(nums, res, path, 0);
        return res;
    }
    
    void DFS(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int begin) {
        if (begin == nums.size()) {
            res.push_back(path);
            return;
        }
        DFS(nums, res, path, begin+1);
        path.push_back(nums[begin]);
        DFS(nums, res, path, begin+1);
        path.pop_back();
    }
};

// Iterative, push nums[i] at the end
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
