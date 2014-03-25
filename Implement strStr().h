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

// KMP algorithm, time complexity O(n)=O(n+m), space complexity O(m)
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int m = strlen(needle);
        if (m == 0) return haystack;
	    vector<int> Pi(m, 0);
	    for (int q=1, k=0; q<m; ++q) {
		    while (k>0 && needle[k]!=needle[q]) k = Pi[k-1];
		    if (needle[k] == needle[q]) ++k;
		    Pi[q] = k;
	    }
	
	    int n = strlen(haystack);
	    for (int i=0, q=0; i<n; ++i) {
		    while (q>0 && needle[q] != haystack[i]) q = Pi[q-1];
		    if (needle[q] == haystack[i]) ++q;
		    if (q == m) return haystack + i - m + 1;
	    }
	    return NULL;
    }
};