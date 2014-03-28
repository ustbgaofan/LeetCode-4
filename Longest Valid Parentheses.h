// Longest Valid Parentheses
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/


// Two-pass Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (!stk.empty()) {
                s[stk.top()] = '#';
                stk.pop();
                s[i] = '#';
            }
        }
        int res = 0;
        for (int i=0, count=0; i<s.size(); ++i) {
            if (s[i] != '#') count = 0;
            else res = max(res, ++count);
        }
        return res;
    }
};

// One-pass Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
		stack<int> stk;
		int len = 0;
		for (int i=0; i<s.size(); ++i) {
			if (s[i]==')' && !stk.empty() && s[stk.top()]=='(') {
			    stk.pop();
				if (stk.empty()) len = max(len, i+1);
				else len = max(len, i-stk.top());
			} else {
			    stk.push(i);
			}
		}
		return len;
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
    	vector<int> dp(N, 0);
        int res = 0;
        for (int i=N-2; i>=0; --i) {
            if (s[i] == '(') {
                int j = i + dp[i+1] + 1;
                if (j<N && s[j]==')') {
                    dp[i] = dp[i+1] + 2;
                    if (j+1 < N) dp[i] += dp[j+1];
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

// Recursive Version, Time Limit Exceeded, time complexity O(2^n), space complexity O(n)
class Solution {
public:
    int longestValidParentheses(string &s, int i, int &len) {
        if (i+1 >= s.size()) return 0;
        int res = longestValidParentheses(s, i+1, len);
        if (s[i] == ')') return 0;
        int j = i + res + 1;
        if (j<s.size() && s[j]==')') {
            res += 2 + longestValidParentheses(s, j+1, len);
            len = max(len, res);
            return res;
        }
        return 0;
    }
    
    int longestValidParentheses(string s) {
        int len = 0;
        longestValidParentheses(s, 0, len);
        return len;
    }
};

// Top-down Dynamic Programming Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int longestValidParentheses(string &s, int i, int &len, vector<int> &mem) {
        if (i+1 >= s.size()) return 0;
        if (mem[i] != -1) return mem[i];
        int res = longestValidParentheses(s, i+1, len, mem);
        if (s[i] == ')') return mem[i] = 0;
        int j = i + res + 1;
        if (j<s.size() && s[j]==')') {
            res += 2 + longestValidParentheses(s, j+1, len, mem);
            len = max(len, res);
            return mem[i] = res;
        }
        return mem[i] = 0;
    }
    
    int longestValidParentheses(string s) {
        int len = 0;
        vector<int> mem(s.size(), -1);
        longestValidParentheses(s, 0, len, mem);
        return len;
    }
};

// Two Scans, time complexity O(n), space complexity O(1), ()(()->(()
class Solution {
public:
    int longestValidParentheses(string &s, int begin, int end, char c, int step) {
        int maxLen = 0, len = 0, count = 0;  
        for (int i=begin; i!=end; i+=step) {  
            if (s[i] == c) {
                ++count;
            } else {
                if (count > 0) {
                    len += 2;  
                    if (--count == 0) maxLen = max(maxLen, len);  
                } else {
                    len = 0;  
                }
            }
        }
        return maxLen;  
    }
    
    int longestValidParentheses(string s) {
        int N = s.size();
        return max(longestValidParentheses(s, 0, N, '(', 1), longestValidParentheses(s, N-1, -1, ')', -1));
    }
};