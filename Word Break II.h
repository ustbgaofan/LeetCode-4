// Word Break II
/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/


// Top-down Dynamic Programming Version, time complexity O(n^2)
class Solution {
public:
    vector<string> DFS(const string &s, int begin, const unordered_set<string> &dict, vector<vector<string>> &mem, vector<bool> &visited) {
        if (visited[begin]) return mem[begin];
        for (int i=begin; i<s.size(); ++i) {
            string path = s.substr(begin, i-begin+1);
            if (dict.find(path) != dict.end()) {
                if (i+1 == s.size()) {
                    mem[begin].push_back(path);
                } else {
					vector<string> res = DFS(s, i+1, dict, mem, visited);
					for (int j=0; j<res.size(); ++j) mem[begin].push_back(path+" "+res[j]);
				}
            }
        }
        visited[begin] = true;
        return mem[begin];
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<string>> mem(s.size());
        vector<bool> visited(s.size(), false);
        return DFS(s, 0, dict, mem, visited);
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n^2)
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