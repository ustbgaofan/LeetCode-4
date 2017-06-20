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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> mem(s.size(), -1);
        return DFS(s, 0, dict, mem);
    }
    
    bool DFS(const string& s, int i, const unordered_set<string>& dict, vector<int>& mem) {
        if (i == s.size()) return true;
        if (mem[i] != -1) return mem[i];
        for (int j=i; j<s.size(); ++j) {
            if (dict.find(s.substr(i, j-i+1)) == dict.end()) continue;
            if (DFS(s, j+1, dict, mem)) return mem[i] = true;
        }
        return mem[i] = false;
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n^2), space complexity O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> mem(s.size()+1, false);
        mem.back() = true;
        for (int i=s.size()-1; i>=0; --i) {
            for (int j=i; j<s.size(); ++j) {
                if (mem[j+1] && dict.find(s.substr(i, j-i+1))!=dict.end()) {
                    mem[i] = true;
                    break;
                }
            }
        }
        return mem[0];
    }
};
