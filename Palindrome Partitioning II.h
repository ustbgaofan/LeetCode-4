//Palindrome Partitioning II
/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/


// Recursive Version, Time Limit Exceeded
class Solution {
public:
    bool isPalindrome(const string &s, int begin, int end) {
        for (int i=begin, j=end; i<j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    
    int DFS(const string &s, int begin) {
        int N = s.size(), res = N - begin - 1;
        for (int i=begin; i<N; ++i) {
            if (!isPalindrome(s, begin, i)) continue;
            res = min(res, 1+DFS(s, begin+1));
        }
        return res;
    }
    
    int minCut(string s) {
        return DFS(s, 0);
    }
};

// Top-down Dynamic Programming Version, time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    int DFS(const string &s, int begin, vector<int> &mem, vector<vector<bool>> &isP) {
        int N = s.size(), res = N - begin - 1;
        if (begin == N) return res;
        if (mem[begin] != -1) return mem[begin];
        for (int i=begin; i<N; ++i) {
            if (!isP[begin][i]) continue;
            res = min(res, 1+DFS(s, i+1, mem, isP));
        }
        return mem[begin] = res;
    }
    
    int minCut(string s) {
        int N = s.size();
        vector<vector<bool>> isP(N, vector<bool>(N));
        for (int i=N-1; i>=0; --i) {
            for (int j=i; j<N; ++j) {
                isP[i][j] = s[i]==s[j] && (j-i<2 || isP[i+1][j-1])? true: false;
            }
        }
        vector<int> mem(N, -1);
        return DFS(s, 0, mem, isP);
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        vector<int> mem(N);
        vector<vector<bool>> isP(N, vector<bool>(N));
        for (int i=N-1; i>=0; --i) {
            mem[i] = N - i - 1;
            for (int j=i; j<N; ++j) {
                isP[i][j] = s[i]==s[j] && (j-i<2 || isP[i+1][j-1])? true: false;
                if (!isP[i][j]) continue;
                if (j+1 < N) mem[i] = min(mem[i], 1+mem[j+1]);
                else mem[i] = 0;
            }
        }
        return mem[0];
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n^2), space complexity O(n)
class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        vector<int> mem(N);
        vector<bool> isP(N);
        for (int i=N-1; i>=0; --i) {
            mem[i] = N - i - 1;
            bool t;
            for (int j=i; j<N; ++j) {
                bool tt = isP[j];
                isP[j] = s[i]==s[j] && (j-i<2 || t)? true: false;
                t = tt;
                if (!isP[j]) continue;
                if (j+1 < N) mem[i] = min(mem[i], 1+mem[j+1]);
                else mem[i] = 0;
            }
        }
        return mem[0];
    }
};