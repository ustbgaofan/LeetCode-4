// Longest Palindromic Substring
/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/


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

// Bottom-up Dynamic Programming Version, time complexity O(n^2), space complexity O(1)
class Solution {
public:
    string longestPalindrome(string s) {
		int N = s.size(), len = 0, l = 0;
	    for (int i=0; i<N; ++i) {
		    for (int t=0; t<2; ++t) {
		        bool mem = true;
		        for (int j=i, k=i+t; j>=0 && k<N; --j, ++k) {
			        if (s[j]==s[k] && mem) {
				        mem = true;
				        if (k-j+1 > len) len = k - j + 1, l = j;
			        } else {
				        mem = false;
			        }
		        }
		    }
	    }
	    return s.substr(l, len);
	}
};

// Manacher's Algorithm, time complexity O(n), space complexity O(n)
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

/************************************************   messy codes   ****************************************************/

/*******
1st clue
*******/
// Naive Iterative Version, Time Limit Exceeded, time complexity O(n^3), space complexity O(1)
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


/*******
2nd clue
*******/
// Naive Recursive Version, Time Limit Exceeded, slower than 1st clue
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

// Naive Top-down Dynamic Programming Version, Time Limit Exceeded
// time complexity O(n^3), space complexity O(n^2)
// practically slower than 1st clue, due to copy, vector and recursion 
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


/*******
3nd clue
*******/
// Recursive Version, Time Limit Exceeded, time complexity O(3^n)
class Solution {
public:
    string longestPalindrome(const string &s, int l, int r) {
	    if (l > r) return "";
	    if (l == r) return s.substr(l, 1);
	    if (s[l] == s[r]) {
		    string str = longestPalindrome(s, l+1, r-1);
		    if (str.size() == r-l-1) return s[l] + str + s[r];
	    }
	    string str1 = longestPalindrome(s, l, r-1);
	    if (str1.size() == r-l) return str1;
	    string str2 = longestPalindrome(s, l+1, r);
	    return str1.size()>=str2.size()? str1: str2;
    }

    string longestPalindrome(string s) {
	    return longestPalindrome(s, 0, s.size()-1);
    }
};

// Top-down Dynamic Programming Version, Time Limit Exceeded, its value copy is time-consuming
// time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    string longestPalindrome(const string &s, int l, int r, vector<vector<string>> &mem) {
	    if (l > r) return "";
	    if (mem[l][r] != "#") return mem[l][r];
	    if (l == r) return mem[l][r].assign(s, l, 1);
	    if (s[l] == s[r]) {
		    mem[l][r] = longestPalindrome(s, l+1, r-1, mem);
		    if (mem[l][r].size() == r-l-1) return mem[l][r] = s[l] + mem[l][r] + s[r];
	    }
	    mem[l][r] = longestPalindrome(s, l, r-1, mem);
	    if (mem[l][r].size() == r-l) return mem[l][r];
	    string str = longestPalindrome(s, l+1, r, mem);
	    return mem[l][r] = mem[l][r].size()>=str.size()? mem[l][r]: str;
    }

    string longestPalindrome(string s) {
	    int N = s.size();
	    vector<vector<string>> mem(N, vector<string>(N, "#"));
	    return longestPalindrome(s, 0, N-1, mem);
    }
};

// Improved Top-down Dynamic Programming Version, Time Limit Exceeded
// time complexity O(n^2), space complexity O(n^2)
// Time Limit Exceeded, turn vector into static array (not dynamic) and use 'char' instead of 'int' could be OK in OJ!
class Solution {
public:
	int longestPalindrome(const string &s, int l, int r, vector<vector<int>> &mem, int &len, int &i) {
		if (l > r) return 1;
		if (mem[l][r] != -1) return mem[l][r];
		if (s[l]==s[r] && longestPalindrome(s,l+1,r-1,mem,len,i)==1) {
			if (r-l+1 > len) len = r -l + 1, i = l;
			return mem[l][r] = 1;
		}
		longestPalindrome(s, l, r-1, mem, len, i);
		longestPalindrome(s, l+1, r, mem, len, i);
		return mem[l][r] = 0;
	}

	string longestPalindrome(string s) {
		int N = s.size(), len = 0, i = 0;
		vector<vector<int>> mem(N, vector<int>(N, -1));
		longestPalindrome(s, 0, N-1, mem, len, i);
		return s.substr(i, len);
	}
};

// Bottom-up Dynamic Programming Version, Time Limit Exceeded, its value copy is time-consuming
// time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
	    int N = s.size();
	    vector<vector<string>> mem(N, vector<string>(N));
	    for (int i=0; i<N; ++i) {
		    for (int j=0; j<N-i; ++j) {
			    if (s[j]==s[j+i] && (i<=1 || mem[j+1][j+i-1].size()==i-1)) mem[j][j+i].assign(s, j, i+1);
			    else mem[j][j+i] = mem[j][j+i-1].size()>=mem[j+1][j+i].size()? mem[j][j+i-1]: mem[j+1][j+i];
		    }
	    }
	    return mem[0][N-1];      
    }
};

// Improved Bottom-up Dynamic Programming Version
// time complexity O(n^2), space complexity O(n^2)
// Time Limit Exceeded, turn vector into static array (not dynamic) could be OK in OJ!
class Solution {
public:
    string longestPalindrome(string s) {
		int N = s.size(), len = 0, l = 0;
		vector<vector<bool>> mem(N, vector<bool>(N, false));
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N-i; ++j) {
				if (s[j]==s[j+i] && (i<=1 || mem[j+1][j+i-1])) {
					mem[j][j+i] = true;
					if (i+1 > len) len = i + 1, l = j;
				}
			}
		}
		return s.substr(l, len);
	}
};

// Different Direction Bottom-up Dynamic Programming Version, Time Limit Exceeded, its value copy is time-consuming
// time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
		if (s.empty()) return s;
	    int N = s.size();
	    vector<vector<string>> mem(N, vector<string>(N));
	    for (int i=N-1; i>=0; --i) {
		    for (int j=i; j<N; ++j) {
			    if (s[i]==s[j] && (j-i<=1 || mem[i+1][j-1].size()==j-i-1)) mem[i][j].assign(s, i, j-i+1);
			    else mem[i][j] = mem[i][j-1].size()>=mem[i+1][j].size()? mem[i][j-1]: mem[i+1][j];
		    }
	    }
	    return mem[0][N-1]; 
	}
};

// Improved Different Direction Bottom-up Dynamic Programming Version
// time complexity O(n^2), space complexity O(n^2)
// Time Limit Exceeded, turn vector into static array (not dynamic) could be OK in OJ!
class Solution {
public:
    string longestPalindrome(string s) {
		int N = s.size(), len = 0, l = 0;
	    vector<vector<bool>> mem(N, vector<bool>(N, false));
	    for (int i=N-1; i>=0; --i) {
		    for (int j=i; j<N; ++j) {
			    if (s[i]==s[j] && (j-i<=1 || mem[i+1][j-1])) {
				    mem[i][j] = true;
				    if (j-i+1 > len) len = j - i + 1, l = i;
			    }
		    }
	    }
	    return s.substr(l, len);
	}
};

// Improved Different Direction Bottom-up Dynamic Programming Version
// time complexity O(n^2), space complexity O(n)
// Time Limit Exceeded, turn vector into static array (not dynamic) could be OK in OJ!
class Solution {
public:
    string longestPalindrome(string s) {
		int N = s.size(), len = 0, l = 0;
	    vector<vector<bool>> mem(2, vector<bool>(N, false));
	    for (int i=N-1; i>=0; --i) {
		    for (int j=i; j<N; ++j) {
			    if (s[i]==s[j] && (j-i<=1 || mem[(i+1)%2][j-1])) {
				    mem[i%2][j] = true;
				    if (j-i+1 > len) len = j - i + 1, l = i;
			    } else {
			        mem[i%2][j] = false;
			    }
		    }
	    }
	    return s.substr(l, len);
	}
};