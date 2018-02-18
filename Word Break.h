// Word Break
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

// Recursive
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return DFS(s, 0, dict);
    }
    
    bool DFS(const string& s, int i, const unordered_set<string>& dict) {
        if (i == s.size()) return true;
        for (int j=i; j<s.size(); ++j) {
            if (dict.find(s.substr(i, j-i+1)) == dict.end()) continue;
            if (DFS(s, j+1, dict)) return true;
        }
        return false;
    }
};

// Top-down Dynamic Programming, time O(n^2), space O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> m(s.size(), -1);
        return DFS(s, 0, dict, m);
    }
    
    int DFS(const string& s, int i, const unordered_set<string>& dict, vector<int>& m) {
        if (i == s.size()) return true;
        if (m[i] != -1) return m[i];
        for (int j=i; j<s.size(); ++j) {
            if (dict.find(s.substr(i, j-i+1)) == dict.end()) continue;
            if (DFS(s, j+1, dict, m)) return m[i] = true; 
        }
        return m[i] = false;
    }
};

// Bottom-up Dynamic Programming, time O(n^2), space O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int N = s.size();
        vector<bool> m(N+1, false);
        m.back() = true;
        for (int i=N-1; i>=0; --i) {
            for (int j=i; j<N; ++j) {
                if (m[j+1] && dict.find(s.substr(i, j-i+1))!=dict.end()) {
                    m[i] = true;
                    break;
                }
            }
        }
        return m[0];
    }
};
