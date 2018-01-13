// Word Break II
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/


// Top-down Dynamic Programming, time O(2^n), space O(2^n)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<string>> m(s.size());
        vector<bool> v(s.size(), false);
        return DFS(s, dict, 0, m, v);
    }
    
    vector<string> DFS(const string& s, const unordered_set<string>& dict, int i, vector<vector<string>>& m, vector<bool>& v) {
        if (v[i]) return m[i];
        v[i] = true;
        for (int j=i; j<s.size(); ++j) {
            string path = s.substr(i, j-i+1);
            if (dict.find(path) == dict.end()) continue;
            if (j+1 == s.size()) {
                m[i].push_back(path);
            } else {
                vector<string> res = DFS(s, dict, j+1, m, v);
                for (int k=0; k<res.size(); ++k) m[i].push_back(path+" "+res[k]);
            }
        }
        return m[i];
    }
};

// Bottom-up Dynamic Programming, time O(2^n), space O(2^n)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int N = s.size();
        vector<vector<string>> mem(N+1);
        mem[N].push_back("*");
        for (int i=N-1; i>=0; --i) {
            for (int j=i; j<N; ++j) {
                string path = s.substr(i, j-i+1);
                if (mem[j+1].empty() || dict.find(path)==dict.end()) continue;
                if (j+1 == N) {
                    mem[i].push_back(path);
                } else {
                    for (int k=0; k<mem[j+1].size(); ++k) {
                        mem[i].push_back(path+" "+mem[j+1][k]);
                    }
                }
            }
        }
        return mem[0];
    }
};
