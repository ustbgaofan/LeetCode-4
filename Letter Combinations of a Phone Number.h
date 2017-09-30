// Letter Combinations of a Phone Number
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

// Naive Version, with vector copy 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> h = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res(1, "");
        for (int i=0; i<digits.size(); ++i) {
            string& str = h[digits[i]-'0'];
            vector<string> res2;
            for (int j=0; j<res.size(); ++j) {
                for (int k=0; k<str.size(); ++k) {
                    res2.push_back(res[j]+str[k]);
                }
            }
            res = res2;
        }
        return res;
    }
};

// Advanced Version, in place method.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> h = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res(1, "");
        for (int i=0; i<digits.size(); ++i) {
            string& str = h[digits[i]-'0'];
            int N = res.size();
            for (int j=0; j<N; ++j) {
                for (int k=1; k<str.size(); ++k) {
                    res.push_back(res[j]+str[k]);
                }
                res[j] += str[0];
            }
        }
        return res;
    }
};

// DFS Version
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> h = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string path;
        DFS(res, path, digits, h);
        return res;
    }
    
    void DFS(vector<string>& res, string& path, const string& digits, const vector<string>& h) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        const string& str = h[digits[path.size()]-'0'];
        for (int i=0; i<str.size(); ++i) {
            path.push_back(str[i]);
            DFS(res, path, digits, h);
            path.pop_back();
        }
    }
};
