// Word Break
/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/


// Top-down Dynamic Programming Version, time complexity O(n^2), space complexity O(n)
class Solution {
public:
    bool DFS(const string &s, int begin, const unordered_set<string> &dict, vector<int> &mem) {
        int N = s.size();
        if (begin == N) return true;
        if (mem[begin] != -1) return mem[begin];
        for (int i=begin; i<N; ++i) {
            if (dict.find(s.substr(begin, i-begin+1)) != dict.end()) {
                if (DFS(s, i+1, dict, mem)) return mem[begin] = true;
            }
        }
        return mem[begin] = false;
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<int> mem(s.size(), -1);
        return DFS(s, 0, dict, mem);
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n^2), space complexity O(n)
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<bool> mem(N+1, false);
        mem[N] = true;
        for (int i=N-1; i>=0; --i) {
            for (int j=i; j<N; ++j) {
                if (mem[j+1] && dict.find(s.substr(i, j-i+1))!=dict.end()) {
                    mem[i] = true;
                    break;
                }
            }
        }
        return mem[0];
    }
};