// Longest Palindromic Substring
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
 

Example:

Input: "cbbd"

Output: "bb"
*/

// Brute force, time O(n^3), space O(1) 
class Solution {
public:   
    string longestPalindrome(string s) {
        int N = s.size(), cnt = 0;
        string res;
        for (int i=0; i<N; ++i) {
            for (int j=i+cnt; j<N; ++j) {
                if (isPalindrome(s, i, j) && (j-i+1)>cnt) {
                    cnt = j-i+1;
                    res = s.substr(i, j-i+1); 
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(const string &s, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};

// Searching for symmetric pairs, time O(n^2), space O(1)
class Solution {
public:   
    string longestPalindrome(string s) {
        int N = s.size();
	string res;
	for (int i=0; i<N; ++i) {
            string t = longestPalindrome(s, i, i);
            if (t.size() > res.size()) res = t;
            t = longestPalindrome(s, i, i+1);
            if (t.size() > res.size()) res = t;
	}
	return res;
    }
    
    string longestPalindrome(const string& s, int l, int r) {
        while (l>=0 && r<s.size() && s[l]==s[r]) --l, ++r;
	return s.substr(l+1, r-l-1);
    }
};

// Manacher's Algorithm, time O(n), space O(n)
class Solution {
public:
    string longestPalindrome(string s) {
	int N = 2*s.size() + 1;
        vector<int> P(N);
        for (int i=0, C=0, R=0; i<N; ++i) {
            int j = 2*C - i;  // mirror
            P[i] = R>i? min(P[j], R-i): 0;
            int left = i - P[i] - 1, right = i + P[i] + 1;
            for (; left>=0 && right<N; --left, ++right) {
                if (left%2==0 || s[left/2]==s[right/2]) ++P[i];
                else break;
            }
            if (i+P[i] > R) {
                C = i;
                R = C + P[C];
            }
        }
        int res = 0;
        for (int i=1; i<N; ++i) {
            if (P[i] > P[res]) res = i;
        }
        return s.substr((res-P[res])/2, P[res]);
    }
};
