// Implement strStr()
/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/


// Two-pass Version, time complexity O(nm), space complexity O(1)
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack), m = strlen(needle);
        for (int i=0; i<=n-m; ++i) {
            int j = 0;
            for (; j<m; ++j) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == m) return haystack + i; 
        }
        return NULL;
    }
};

// One-pass Version, time complexity O(nm), space complexity O(1), faster than 1st version 
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        for (; ; ++haystack) {
            char *h = haystack, *n = needle;
            for (; *n!='\0' && *h==*n; ++h, ++n);
            if (*n == '\0') return haystack;
            if (*h == '\0') return NULL;
        }
    }
};