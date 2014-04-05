// Permutations 
/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/


// time complexity O(n!), space complexity O(n)
class Solution {
public:
    void DFS(vector<vector<int>> &res, vector<int> &path, vector<pair<int, bool>> &vec) {
        if (path.size() == vec.size()) {
            res.push_back(path);
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
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        vector<int> path;
        vector<pair<int, bool>> vec;
        for (int i=0; i<num.size(); ++i) {
			vec.push_back(make_pair(num[i], false));
		}
        DFS(res, path, vec);
        return res;
    }
};