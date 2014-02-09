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
        vector<string> res;
        if (digits.size() == 0) {
            res.push_back(""); 
            return res;
        }
	    string mapping[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	    string str = mapping[digits[0]-'2'];
	    for (int i=0; i<str.size(); ++i) {
		    string t = "";
		    res.push_back(t + str[i]);
	    }
	    for (int i=1; i<digits.size(); ++i) {
		    str = mapping[digits[i]-'2'];
		    int size1 = res.size(), size2 = str.size();
		    vector<string> temp(res); 
		    res.resize(size1*size2);
		    for (int j=0; j<size1; ++j) {
			    for (int k=0; k<size2; ++k) {
				    res[j*size2+k] = temp[j] + str[k];
			    }
		    }
	    }
	    return res;
    }
};

// Advanced Version, less code, in place method.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mapping[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res(1, "");
        for (int i=0; i<digits.size(); ++i) {
            string str = mapping[digits[i]-'2'];
            for (int j=res.size()-1; j>=0; --j) {
                for (int k=1; k<str.size(); ++k) 
                    res.push_back(res[j] + str[k]);
                res[j] += str[0];
            }
        }
        return res;
    }
};

// DFS Version
class Solution {
public:
    void DFS(vector<string>& res, string& path, const string& digits, string mapping[]) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        string str = mapping[digits[path.size()]-'2'];
        for (int i=0; i<str.size(); ++i) {
            path.push_back(str[i]);
            DFS(res, path, digits, mapping);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string mapping[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string path;
        DFS(res, path, digits, mapping);
        return res; 
    }
};