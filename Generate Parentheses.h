// Generate Parentheses
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/


class Solution {
public:
    void generateParenthesis(vector<string>& res, const string& path, int l, int r) {
        if (l==0 && r==0) res.push_back(path);
        if (l > 0) generateParenthesis(res, path+"(", l-1, r);
        if (r > l) generateParenthesis(res, path+")", l, r-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(res, "", n, n);
        return res;
    }
};