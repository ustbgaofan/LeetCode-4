// Valid Parentheses
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


// Stack, time O(n), space O(n) 
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> h;
        h[')'] = '(';
        h[']'] = '[';
        h['}'] = '{';
        stack<char> stk;
        int N = s.size();
        for (int i=0; i<N; ++i) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{' ) {
                stk.push(s[i]);
            } else {
                if (stk.empty() || h[s[i]]!=stk.top()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
