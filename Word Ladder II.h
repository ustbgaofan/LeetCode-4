// Word Ladder II
/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

// BFS, time O(n), space O(n), n = len(wordList)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> h(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> trace;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int k = q.size();
            bool flag = false;
            vector<string> del;
            for (int i=0; i<k; ++i) {
                string f = q.front();
                q.pop();
                string b = f;
                if (f == endWord) flag = true;
                for (int i=0; i<f.size(); ++i) {
                    char t = f[i];
                    for (char c='a'; c<='z'; ++c) {
                        f[i] = c;
                        if (h.find(f) == h.end()) continue;
                        q.push(f);
                        del.push_back(f);  // corner case!
                        trace[f].insert(b);
                    }
                    f[i] = t;
                }
            }
            for (string s : del) h.erase(s);
            if (flag) break;
        }
        vector<vector<string>> res;
        vector<string> path = {endWord};
        traceBack(res, trace, path, beginWord, endWord);
        return res;
    }
    
    void traceBack(vector<vector<string>>& res, unordered_map<string, unordered_set<string>>& trace, 
                   vector<string>& path, string beginWord, string endWord) {
        if (beginWord == endWord) {
            res.push_back(path);
            reverse(res.back().begin(), res.back().end());
            return;
        }
        if (trace.find(endWord) == trace.end()) return;
        for (auto s : trace[endWord]) {
            path.push_back(s);
            traceBack(res, trace, path, beginWord, s);
            path.pop_back();
        }
    }
};
