// Combination Sum
/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/


// Version 1, start from big to small
class Solution {
public:
    int searchInsert(vector<int> &v, int target) {
        int begin = 0, end = v.size() - 1, mid;
        while (begin <= end) {
            mid = (begin + end)/2;
            if (v[mid] == target) return mid;
            else if (v[mid] < target) begin = mid + 1;
            else end = mid - 1;
        }
		return begin;
    }
    
    void DFS(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates, int start, int target) {
        if (target == 0) {
            res.push_back(path);  // first push then reverse!
            reverse(res.back().begin(), res.back().end());
            return;
        }
        int newStart = searchInsert(candidates, target);
        start = newStart<start ? newStart: start;
        while (start>=0 && candidates[start]>target) --start;
        for (int i=start; i>=0; --i) {
            path.push_back(candidates[i]);
            DFS(res, path, candidates, i, target-candidates[i]);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        DFS(res, path, candidates, candidates.size()-1, target);
        return res;
    }
};

// Version 2, start from small to big, without reverse, without binary search
class Solution {
public:
    void DFS(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates, int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i=start; i<candidates.size() && candidates[i]<=target; ++i) {
            path.push_back(candidates[i]);
            DFS(res, path, candidates, i, target-candidates[i]);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        DFS(res, path, candidates, 0, target);
        return res;
    }
};