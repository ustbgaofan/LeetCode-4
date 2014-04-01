// Combination Sum II
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/


// Naive Version, using set to avoid duplicates
class Solution {
public:
    void DFS(set<vector<int>> &res, vector<int> &path, vector<int> &num, int start, int target) {
        if (target == 0) {
            res.insert(path);
            return;
        }
        for (int i=start; i<num.size() && num[i]<=target; ++i) {
            path.push_back(num[i]);
            DFS(res, path, num, i+1, target-num[i]);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        set<vector<int>> res;
        vector<int> path;
        sort(num.begin(), num.end());
        DFS(res, path, num, 0, target);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};

// Advanced Version, avoiding duplicates without set
class Solution {
public:
    void DFS(vector<vector<int>> &res, vector<int> &path, vector<int> &num, int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i=start; i<num.size() && num[i]<=target; ++i) {
            if (i>start && num[i]==num[i-1]) continue;
            path.push_back(num[i]);
            DFS(res, path, num, i+1, target-num[i]);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(num.begin(), num.end());
        DFS(res, path, num, 0, target);
        return res;
    }
};