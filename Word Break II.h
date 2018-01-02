// Word Break II
/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/


// Top-down Dynamic Programming Version, time O(n^2)
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

// Bottom-up Dynamic Programming Version, time O(n^2)
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<vector<string>> mem(N+1);
        mem[N].push_back("*");
        for (int i=N-1; i>=0; --i) {
            for (int j=i; j<N; ++j) {
                string path = s.substr(i, j-i+1);
                if (!mem[j+1].empty() && dict.find(path)!=dict.end()) {
                    if (j+1 == N) {
                        mem[i].push_back(path);
                    } else {
                        for (int k=0; k<mem[j+1].size(); ++k) {
                            mem[i].push_back(path+" "+mem[j+1][k]);
                        }
                    }
                }
            }
        }
        return mem[0];
    }
};
