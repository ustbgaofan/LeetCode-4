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


// Version 1, standard DFS
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

// Version 2, every element has 2 choices, transformation from Subsets version 2 
class Solution {
public:
    void DFS(vector<vector<int>> &res, vector<int> &path, int n, int k, int begin) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        if (begin == n+1) return;
        path.push_back(begin);
        DFS(res, path, n, k, begin+1);
        path.pop_back();
        DFS(res, path, n, k, begin+1);
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(res, path, n, k, 1);
        return res;
    }
};

// Version 3, iterative version of version 2
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res, cand(1);
        for (int i=1; i<=n; ++i) {
            int size = cand.size();
            for (int j=0; j<size; ++j) {
                if (cand[j].size() == k-1) {
                    res.push_back(cand[j]);
                    res.back().push_back(i);
                } else {
                    cand.push_back(cand[j]);
                    cand.back().push_back(i);
                }
            }
        }
        return res;
    } 
};