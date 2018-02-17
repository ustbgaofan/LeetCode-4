// Subsets II 
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/


// (not suggested) Recursive, time O(2^n), space O(n)
// every element has 2 choices
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

// (not suggested) Iterative, time O(2^n), space O(1)
// push nums[i] at the end
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

// More general, time O(2^n), space O(n)
// @ --> 1 --> 1,2 --> 1,2,3
//         --> 1,3
//   --> 2 --> 2,3
//   --> 3
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        DFS(nums, res, path, 0);
        return res;
    }
    
    void DFS(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int i) {
        res.push_back(path);
        for (int j=i; j<nums.size(); ++j) {
            if (j>i && nums[j]==nums[j-1]) continue;
            path.push_back(nums[j]);
            DFS(nums, res, path, j+1);
            path.pop_back();
        }
    }
};
