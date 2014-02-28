// Combinations 
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/


class Solution {
public:
    void DFS(vector<vector<int>> &res, vector<int> &path, int n, int k, int begin) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        int end = n - k + 1 + path.size();
        for (int i=begin; i<=end; ++i) {
            path.push_back(i);
            DFS(res, path, n, k, i+1);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(res, path, n, k, 1);
        return res;
    }
};