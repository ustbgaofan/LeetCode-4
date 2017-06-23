// Subsets II 
/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/


// Version 1, standard DFS
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(1);
        vector<int> path;
        for (int i=1; i<=nums.size(); ++i) DFS(nums, i, res, path, 0);
        return res;
    }
    
    void DFS(const vector<int>& nums, int len, vector<vector<int>>& res, vector<int>& path, int begin) {
        if (path.size() == len) {
            res.push_back(path);
            return;
        }
        int end = nums.size() - (len - path.size());
        for (int i=begin; i<=end; ++i) {
            if (i>begin && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            DFS(nums, len, res, path, i+1);
            path.pop_back();
        }
    }
};

// Version 2, every element has 2 choices
class Solution {
public:
    void DFS(const vector<int> &S, vector<vector<int>> &res, vector<int> &path, int begin, int count) {
        if (begin == S.size()) {
            res.push_back(path);
            return;
        }
        int nextCount = count;
        if (begin+1<S.size() && S[begin+1]==S[begin]) ++nextCount;
        else nextCount = 0;
        if (count==0 || path.size()>=count && path[path.size()-count]==S[begin]) {
            path.push_back(S[begin]);
            DFS(S, res, path, begin+1, nextCount);
            path.pop_back();
        }
        DFS(S, res, path, begin+1, nextCount);
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> res;
        vector<int> path;
        DFS(S, res, path, 0, 0);
        return res;
    }
};

// Version 3, iterative version of version 2
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> res(1);
        for (int i=0, count=0; i<S.size(); ++i) {
            if (i>0 && S[i]==S[i-1]) ++count;
            else count = 0;
            int M = res.size();
            for (int j=0; j<M; ++j) {
                int N = res[j].size();
                if (count==0 || N>=count && res[j][N-count]==S[i]) {
                    res.push_back(res[j]);
                    res.back().push_back(S[i]);
                }
            }
        }
        return res;
    }
};
