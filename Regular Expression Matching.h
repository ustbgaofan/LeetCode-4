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