// Implement strStr()
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/


// time O(nm), space O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int M = haystack.size(), N = needle.size();
        for (int i=0; i<M; ++i) {
            int k = 0;
            for (int j=i; j<M && k<N; ++j, ++k) {
                if (haystack[j] != needle[k]) break;
            }
            if (k == N) return i;
        }
        return -1;
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
