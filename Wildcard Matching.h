// Wildcard Matching
/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/


// Recursive Version, Time Limit Exceeded
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (s.empty()) {
            for (int i=0; i<p.size(); ++i) {
                if (p[i] != '*') return false;
            }
            return true;
        }
        if (p[0] != '*') return (p[0]==s[0] || p[0]=='?') && isMatch(s.substr(1), p.substr(1));
        for (int i=0; i<=s.size(); ++i) {
            if (isMatch(s.substr(i), p.substr(1))) return true;
        }
        return false;
    }
};

// Bottom-up Dynamic Programming, time O(nm), space O(nm)
// We define the state m[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:
// m[i][j] = m[i-1][j-1], if p[j-1]!='*' && (s[i-1]==p[j-1] || p[j-1]=='?');
// m[i][j] = m[i][j-1], if p[j-1]=='*' and the pattern repeats for 0 times;
// m[i][j] = m[i-1][j], if p[j-1]=='*' and the pattern repeats for at least 1 times.
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> m(M+1, vector<bool>(N+1, false));
        m[0][0] = true;
        for (int i=0; i<=M; ++i) {
            for (int j=1; j<=N; ++j) {
                if (p[j-1] != '*') m[i][j] = i>0 && (s[i-1]==p[j-1] || p[j-1]=='?') && m[i-1][j-1];
                else m[i][j] = m[i][j-1] || (i>0 && m[i-1][j]);
            }
        }
        return m[M][N];
    }
};

// Space Optimized Bottom-up Dynamic Programming, time O(nm), space O(n)
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> m(2, vector<bool>(N+1, false));
        m[0][0] = true;
        for (int i=0; i<=M; ++i) {
            if (i > 1) m[i%2][0] = false;
            for (int j=1; j<=N; ++j) {
                if (p[j-1] != '*') m[i%2][j] = i>0 && (s[i-1]==p[j-1] || p[j-1]=='?') && m[(i-1)%2][j-1];
                else m[i%2][j] = m[i%2][j-1] || (i>0 && m[(i-1)%2][j]);
            }
        }
        return m[M%2][N];
    }
};

// Iterative Version, time complexity O(max(m,n))~O(mn), space complexity O(1)
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, k = -1, t = -1;
        while (i < s.size()) {
            if (j<p.size() && (s[i]==p[j] || p[j]=='?')) {
                ++i;
                ++j;
            } else if (j<p.size() && p[j]=='*') {
                k = i;
                t = j++;
            } else if (j==p.size() || s[i]!=p[j]) {
                if (t == -1) return false;
                i = ++k;
                j = t + 1;
            }
        }
        for (; j<p.size(); ++j) {
            if (p[j] != '*') return false;
        }
        return true;
    }
};
