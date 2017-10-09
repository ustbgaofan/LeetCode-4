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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
        int prev = begin - 1;
        while (prev>=0 && nums[begin]==nums[prev]) --prev;
        int sameCnt = begin - 1 - prev;
        if (sameCnt==0 || path.size()>=sameCnt && path[path.size()-sameCnt]==nums[begin]) {
            path.push_back(nums[begin]);
            DFS(nums, res, path, begin+1);
            path.pop_back();
        }
    }
};

// Version 3, iterative version of version 2
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(1);
        for (int i=0, cnt=0; i<nums.size(); ++i) {
            (i>0 && nums[i]==nums[i-1]) ?  ++cnt : cnt=0;
            int k = res.size();
            for (int j=0; j<k; ++j) {
                int N = res[j].size();
                if (cnt==0 || N>=cnt && nums[i]==res[j][N-cnt]) {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                }
            }
        }
        return res;
    }
};

// Version 2, every element has 2 choices
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        DFS(nums, path, 0);
        return res;
    }
    
    void DFS(const vector<int>& nums, vector<int>& path, int begin) {
        if (begin == nums.size()) {
            if (h.insert(path).second) res.push_back(path);
            return;
        }
        DFS(nums, path, begin+1);
        path.push_back(nums[begin]);
        DFS(nums, path, begin+1);
        path.pop_back();
    }
    
private:
    vector<vector<int>> res;
    set<vector<int>> h;
};

// Version 3, iterative version of version 2
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> h;
        vector<vector<int>> res(1);
        for (int i=0; i<nums.size(); ++i) {
            int k = res.size();
            for (int j=0; j<k; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
                if (!h.insert(res.back()).second) res.pop_back();
            }
        }
        return res;
    }
};
