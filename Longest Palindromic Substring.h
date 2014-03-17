// Longest Palindromic Substring
/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/


// Iterative Sliding Windowing Version, Time Limit Exceeded, time complexity O(n^3), space complexity O(1)
class Solution {
public:
    bool isPalindrome(const string &s, int begin, int end) {
        int i = begin, j = end;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int N = s.size();
        for (int len=N; len>0; --len) {
            for (int i=0; i<=N-len; ++i) {
                if (isPalindrome(s, i, i+len-1)) return s.substr(i, len);
            }
        }
        return "";
    }
};

// Recursive Sliding Windowing Version, Time Limit Exceeded, slower than 1st version
class Solution {
public:
    bool isPalindrome(const string &s, int begin, int end) {
	    int i = begin, j = end;
	    while (i < j) {
		    if (s[i++] != s[j--]) return false;
	    }
	    return true;
    }
    
    string longestPalindrome(const string &s, int begin, int end) {
	    if (begin > end) return "";
	    if (isPalindrome(s, begin, end)) return s.substr(begin, end-begin+1);
	    string str1 = longestPalindrome(s, begin, end-1);
	    if (str1.size() == end-begin) return str1;
	    string str2 = longestPalindrome(s, begin+1, end);
	    return str1.size()>=str2.size()? str1: str2;
    }

    string longestPalindrome(string s) {
	    return longestPalindrome(s, 0, s.size()-1);         
    }
};

// Top-down Dynamic Programming Sliding Windowing Version, Time Limit Exceeded
// time complexity O(n^3), space complexity O(n^2)
// practically slower than 1st version, due to copy, vector and recursion 
class Solution {
public:
    bool isPalindrome(const string &s, int begin, int end) {
	    int i = begin, j = end;
	    while (i < j) {
		    if (s[i++] != s[j--]) return false;
	    }
	    return true;
    }
    
    string longestPalindrome(const string &s, int begin, int end, vector<vector<string>> &mem) {
	    if (begin > end) return "";
	    if (mem[begin][end] != "#") return mem[begin][end];
	    if (isPalindrome(s, begin, end)) return mem[begin][end].assign(s, begin, end-begin+1);
	    string str1 = longestPalindrome(s, begin, end-1, mem);
	    if (str1.size() == end-begin) return mem[begin][end] = str1;
	    string str2 = longestPalindrome(s, begin+1, end, mem);
	    return mem[begin][end] = str1.size()>=str2.size()? str1: str2;
    }

    string longestPalindrome(string s) {
        int N = s.size();
        vector<vector<string>> mem(N, vector<string>(N, "#"));
	    return longestPalindrome(s, 0, s.size()-1, mem);         
    }
};

// Searching For Symmetric Pairs Version, time complexity O(n^2), space complexity O(1)
class Solution {
public:
	string longestPalindrome(string s) {
	    int N = s.size();
	    if (N < 2) return s;
	    string res;
	    for (int i=0; i<N-1; ++i) {
	        for (int t=0, l=i-1, r=i+1; t<2; ++t, l=i, r=i+1) {
	            while (l>=0 && r<N && s[l]==s[r]) --l, ++r;
	            if (r-l-1 > res.size()) res.assign(s, l+1, r-l-1);
	        }
	    } 
	    return res;
	}
};