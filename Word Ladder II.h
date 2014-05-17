// Word Ladder II
/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/


class Solution {
public:
    void buildResult(vector<vector<string>> &res, vector<string> &path, unordered_map<string, vector<string>> &backtrace, const string &end) {
        if (backtrace.find(end) == backtrace.end()) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        const vector<string> &v = backtrace[end];
        for (int i=0; i<v.size(); ++i) {
            path.push_back(v[i]);
            buildResult(res, path, backtrace, v[i]);
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> cq, nq;
        cq.insert(start);
        dict.insert(end);
        unordered_map<string, vector<string>> backtrace;
        while (!cq.empty() && cq.find(end)==cq.end()) {
            for (unordered_set<string>::iterator it=cq.begin(); it!=cq.end(); ++it) dict.erase(*it);
            for (unordered_set<string>::iterator it=cq.begin(); it!=cq.end(); ++it) {
                string str = *it;
                for (int i=0; i<str.size(); ++i) {
                    char t = str[i];
                    for (char c='a'; c<='z'; ++c) {    
                        str[i] = c;
                        if (dict.find(str) != dict.end()) {
                            nq.insert(str);
                            backtrace[str].push_back(*it);
                        }
                    }
                    str[i] = t;
                }
            }
            swap(cq, nq);
            nq.clear();
        }
        vector<vector<string>> res;
        vector<string> path(1, end);
        if (!backtrace.empty()) buildResult(res, path, backtrace, end);
        return res;
    }
};