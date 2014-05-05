// Wildcard Matching
/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/


// Recursive Version, Time Limit Exceeded, time complexity O(min(m,n))~O(n^m), space complexity O(min(m,n))
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        if (*s == '\0') return *p == '*';
        if (*p == '*') {
            while (*s != '\0') {
                if (isMatch(s++, p+1)) return true;
            }
            return isMatch(s, p+1);
        }
        return (*p==*s || *p=='?') && isMatch(s+1, p+1);
    }
};

// Bottom-up Dynamic Programming, Memory Limit Exceeded, time complexity O(nm), space complexity O(nm)
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int N = strlen(s), M = strlen(p);
        vector<vector<bool>> mem(M+1, vector<bool>(N+1, false));
        mem[0][0] = true;
        for (int i=1; i<=M; ++i) {
            mem[i][0] = p[i-1]=='*'? mem[i-1][0]: false;
            for (int j=1; j<=N; ++j) {
                if (p[i-1] != '*') mem[i][j] = (p[i-1]=='?' || p[i-1]==s[j-1])? mem[i-1][j-1]: false;
                else mem[i][j] = mem[i-1][j] || mem[i][j-1];
            }
        }
        return mem[M][N];
    }
};

// Space Optimized Bottom-up Dynamic Programming, time complexity O(nm), space complexity O(n)
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int N = strlen(s), M = strlen(p);
		for (int i=0, count=0; p[i]!='\0'; ++i) {  // in order to pass
			if (p[i]!='*' && N<++count) return false;  
		}
        vector<bool> mem(N+1, false);
        mem[0] = true;
        for (int i=1; i<=M; ++i) {
            bool t1 = mem[0];
            mem[0] = p[i-1]=='*'? mem[0]: false;
            for (int j=1; j<=N; ++j) {
                bool t2 = mem[j];
                if (p[i-1] != '*') mem[j] = (p[i-1]=='?' || p[i-1]==s[j-1])? t1: false;
                else mem[j] = mem[j] || mem[j-1];
                t1 = t2;
            }
        }
        return mem[N];
    }
};

// Iterative Version, time complexity O(min(m,n))~O(mn) (m1n1+m2n2<=mn), space complexity O(1)
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *bs = NULL, *bp = NULL;
        while (*s != '\0') {
            if (*s==*p || *p=='?') ++s, ++p;
            else if (*p == '*') bs = s, bp = ++p;
            else if (bs) s = ++bs, p = bp;
            else return false;
        }
        while (*p == '*') ++p;
        return *p == '\0';
    }
};