// Regular Expression Matching
/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/


// time O(n)~O(2^n) (aaab, a*a*a*), space O(n)
// left is string, right is pattern which includes . and *.
// * only occurs from right[1]
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) return s.size()==1 && (p[0]==s[0] || p[0]=='.');
        // case 1: when the second char of p is not '*'
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (p[0]==s[0] || p[0]=='.') && isMatch(s.substr(1), p.substr(1));
        } else {
        // case 2: when the second char of p is *, complex case.
            //case 2.1: a * can stand for 0 element
            if (isMatch(s, p.substr(2))) return true;
            // case 2.2: a * can stand for 1 or more preceding element, so try every sub string
            for (int i=0; i<s.size() && (s[i]==p[0] || p[0]=='.'); ++i) {
                if (isMatch(s.substr(i+1), p.substr(2))) return true;
            }
            return false;
        }
    }
};

// Bottom-up Dynamic Programming, time O(MN), space O(MN)
// We define the state m[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:
// m[i][j] = m[i-1][j-1], if p[j-1]!='*' && (s[i-1]==p[j-1] || p[j-1]=='.');
// m[i][j] = m[i][j-2], if p[j-1]=='*' and the pattern repeats for 0 times;
// m[i][j] = m[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'), if p[j-1]=='*' and the pattern repeats for at least 1 times.
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> m(M+1, vector<bool>(N+1, false));
        m[0][0] = true;
        for (int i=0; i<=M; ++i) {
            for (int j=1; j<=N; ++j) {
                if (p[j-1] != '*') m[i][j] = i>0 && (s[i-1]==p[j-1] || p[j-1]=='.') && m[i-1][j-1];
                else m[i][j] = m[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && m[i-1][j]);
            }
        }
        return m[M][N];
    }
};

// Space Optimized Bottom-up Dynamic Programming, time O(MN), space O(N)
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> m(2, vector<bool>(N+1, false));
        m[0][0] = true;
        for (int i=0; i<=M; ++i) {
            if (i > 1) m[0][0] = m[1][0] = false;
            for (int j=1; j<=N; ++j) {
                if (p[j-1] != '*') m[i%2][j] = i>0 && m[(i-1)%2][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.'); 
                else m[i%2][j] = m[i%2][j-2] || (i>0 && m[(i-1)%2][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
            }
        }
        return m[M%2][N];
    }
};
