// Regular Expression Matching
/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
*/


// 1st Recursive Version, time complexity O(n)~O(2^n) (aaab, a*a*a*), space complexity O(n)
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s && p && *p!='*');
        if (*p == '\0') return *s == '\0';
        if (*(p+1) != '*') {
            return (*p==*s || (*p=='.' && *s!='\0')) && isMatch(s+1, p+1);
        }
        while (*s==*p || (*p=='.' && *s!='\0')) {
            if (isMatch(s++, p+2)) return true;
        }
        return isMatch(s, p+2);
    }
};

// 2nd Recursive Version, time complexity O(n)~O(2^n) (aaab, a*a*a*), space complexity O(n)
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s && p && *p!='*');
        if (*p == '\0') return *s == '\0';
        if (*p==*s || (*p=='.' && *s!='\0')) {
            if (*(p+1) == '*') return isMatch(s, p+2) || isMatch(s+1, p);
            else return isMatch(s+1, p+1);
        } else { 
            return *(p+1)=='*' && isMatch(s, p+2);
        }
    }
};

// Bottom-up Dynamic Programming, time complexity O(mn), space complexity O(mn)
class Solution {
public:
    bool match(char a, char b){
        return a=='.'? true: a==b;
    }
    
    bool isMatch(const char *s, const char *p) {
        int N = strlen(s), M = strlen(p);
        vector<vector<bool>> mem(M+1, vector<bool>(N+1, false));
        mem[0][0] = true; 
        for (int i=1; i<=M; ++i) {
            mem[i][0] = p[i-1]=='*'? mem[i-2][0]: false;
            for (int j=1; j<=N; ++j) {
                if (p[i-1] != '*') mem[i][j] = match(p[i-1], s[j-1])? mem[i-1][j-1]: false;
                else mem[i][j] = match(p[i-2], s[j-1])? (mem[i-2][j] || mem[i][j-1]): mem[i-2][j];
            }
        }
        return mem[M][N];
    }
};

// Space Optimized Bottom-up Dynamic Programming, time complexity O(mn), space complexity O(n)
class Solution {
public:
    bool match(char a, char b){
        return a=='.'? true: a==b;
    }
    
    bool isMatch(const char *s, const char *p) {
        int N = strlen(s), M = strlen(p);
        vector<vector<bool>> mem(3, vector<bool>(N+1, false));
        mem[0][0] = true; 
        for (int i=1; i<=M; ++i) {
            mem[i%3][0] = p[i-1]=='*'? mem[(i-2)%3][0]: false;
            for (int j=1; j<=N; ++j) {
                if (p[i-1] != '*') mem[i%3][j] = match(p[i-1], s[j-1])? mem[(i-1)%3][j-1]: false;
                else mem[i%3][j] = match(p[i-2], s[j-1])? (mem[(i-2)%3][j] || mem[i%3][j-1]): mem[(i-2)%3][j];
            }
        }
        return mem[M%3][N];
    }
};