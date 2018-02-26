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

// Recursive
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return DFS(s, dict, 0);
    }
    
    vector<string> DFS(const string& s, const unordered_set<string>& dict, int i) {
        vector<string> res;
        for (int j=i; j<s.size(); ++j) {
            string path = s.substr(i, j-i+1);
            if (dict.find(path) == dict.end()) continue;
            if (j+1 == s.size()) {
                res.push_back(path);
            } else {
                vector<string> t = DFS(s, dict, j+1);
                for (string str : t) res.push_back(path+" "+str);
            }
        }
        return res;
    }
};

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
                vector<string> t = DFS(s, dict, j+1, m, v);
                for (string str : t) m[i].push_back(path+" "+str);
            }
        }
        return m[i];
    }
};

// Bottom-up Dynamic Programming, time O(2^n), space O(2^n)
// the brute force search is to try all the options whether to insert a space at position i.
// So the total options to search is 2^n, so the time complexity should be O(2^n) n is the length of the sentence to break
// same thing, for the space complexity, it's same all those 2^n can be a valid break, so the space complexity is also O(2^n)
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
                    for (string str : mem[j+1]) mem[i].push_back(path+" "+str);
                }
            }
        }
        return mem[0];
    }
};
