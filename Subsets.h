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


// Version 1, standard DFS, transformation from Combinations version 1  
class Solution {
public:
    void DFS(vector<int> &S, vector<vector<int>> &res, int len, vector<int> &path, int begin) {
        if (len == path.size()) {
            res.push_back(path);
            return;
        }
        int end = S.size() - (len - 1) + path.size();
        for (int i=begin; i<end; ++i) {
            path.push_back(S[i]);
            DFS(S, res, len, path, i+1);
            path.pop_back();
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
        vector<vector<int>> res(1);
        vector<int> path;
        for (int i=1; i<=S.size(); ++i) DFS(S, res, i, path, 0);
        return res;
    }
};

// Version 2, every element has 2 choices
class Solution {
public:
    void DFS(vector<int> &S, vector<vector<int>> &res, vector<int> &path, int begin) {
        if (begin == S.size()) {
            res.push_back(path);
            return;
        }
        path.push_back(S[begin]);
        DFS(S, res, path, begin+1);
        path.pop_back();
        DFS(S, res, path, begin+1);
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> res;
        vector<int> path;
        DFS(S, res, path, 0);
        return res;
    }
};

// Version 3, iterative version of version 2
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
        vector<vector<int>> res(1);
        for (int i=0; i<S.size(); ++i) {
            int size = res.size();
            for (int j=0; j<size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};