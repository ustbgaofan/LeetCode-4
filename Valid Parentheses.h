// Valid Parentheses
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


// Non-hash Version
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int size = s.size();
        for (int i=0; i<size; ++i) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{' ) stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                char c = stk.top();
                if (s[i]==')' && c!='(' || s[i]==']' && c!='[' || s[i]=='}' && c!='{') 
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

// Hash Version 
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash;
        hash[')'] = '(';
        hash[']'] = '[';
        hash['}'] = '{';
        stack<char> stk;
        int size = s.size();
        for (int i=0; i<size; ++i) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{' ) stk.push(s[i]);
            else {
                if (stk.empty() || hash[s[i]]!=stk.top()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};