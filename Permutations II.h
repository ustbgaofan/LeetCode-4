// Permutations II
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/


// Naive Version, Time Limit Exceeded, using set to avoid duplicates
class Solution {
public:
    void DFS(set<vector<int>> &res, vector<int> &path, vector<pair<int, bool>> &vec) {
        if (path.size() == vec.size()) {
            res.insert(path);
            return;
        }
        for (int i=0; i<vec.size(); ++i) {
            if (!vec[i].second) {
                vec[i].second = true;
                path.push_back(vec[i].first);
                DFS(res, path, vec);
                vec[i].second = false;
                path.pop_back();
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        set<vector<int>> res;
        vector<int> path;
        vector<pair<int, bool>> vec;
        for (int i=0; i<num.size(); ++i) vec.push_back(make_pair(num[i], false));
        DFS(res, path, vec);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};

// Advanced Version, avoiding duplicates without set, time complexity O(n!), space complexity O(n)
class Solution {
public:
    void DFS(vector<vector<int>> &res, vector<int> &path, vector<pair<int, bool>> &vec) {
        if (path.size() == vec.size()) {
            res.push_back(path);
            return;
        }
        for (int i=0; i<vec.size(); ++i) {
            if (vec[i].second) continue;
            if (i>0 && vec[i].first==vec[i-1].first && !vec[i-1].second) continue;
            vec[i].second = true;
            path.push_back(vec[i].first);
            DFS(res, path, vec);
            vec[i].second = false;
            path.pop_back();
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<pair<int, bool>> vec;
        for (int i=0; i<num.size(); ++i) vec.push_back(make_pair(num[i], false));
        DFS(res, path, vec);
        return res;
    }
};

// Advanced Version, time complexity O(n!), space complexity O(n^2) FOR SETs
class Solution {
public:
    void DFS(vector<int> &num, int begin, vector<vector<int>> &res) {
        int end = num.size();
        if (begin == end) {
            res.push_back(num);
            return;
        }
        unordered_set<int> visited;
        for (int i=begin; i<end; ++i) {
            if (!((visited.insert(num[i])).second)) continue;
            swap(num[begin], num[i]);
            DFS(num, begin+1, res);
            swap(num[begin], num[i]);
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        DFS(num, 0, res);
        return res;
    }
};