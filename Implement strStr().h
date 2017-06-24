// Implement strStr()
/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/


// time complexity O(nm), space complexity O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = haystack.size(), N = needle.size();
        for (int i=0; i<=M-N; ++i) {
            int j = 0;
            for (int k=i; j<N; ++j, ++k) {
                if (needle[j] != haystack[k]) break;
            }
            if (j == N) return i;
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
