// Distinct Subsequences
/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/


// Recursive Version, Time Limit Exceeded 
class Solution {
public:
    int numDistinct(string S, int i, string T, int j) {
        if (j == T.size()) return 1;
        int res = 0;
        for (int k=i; k<S.size(); ++k) {
            if (S[k] == T[j]) res += numDistinct(S, k+1, T, j+1);
        }
        return res;
    }
    
    int numDistinct(string S, string T) {
        return numDistinct(S, 0, T, 0);  
    }
};

// Top-down Dynamic Programming Version, time complexity O(nm), space complexity O(nm)
class Solution {
public:
    int numDistinct(string S, int i, string T, int j, vector<vector<int>> &mem) {
        if (j == T.size()) return 1;
        if (i == S.size()) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        int res = 0;
        for (int k=i; k<S.size(); ++k) {
            if (S[k] == T[j]) res += numDistinct(S, k+1, T, j+1, mem);
        }
        return mem[i][j] = res;
    }
    
    int numDistinct(string S, string T) {
        vector<vector<int>> mem(S.size(), vector<int>(T.size(), -1));
        return numDistinct(S, 0, T, 0, mem);  
    }
};

// Recursive Version, Time Limit Exceeded 
class Solution {
public:
    int numDistinct(string S, int i, string T, int j) {
        if (j == T.size()) return 1;
        if (i == S.size()) return 0;
        int res = numDistinct(S, i+1, T, j);
        if (S[i] == T[j]) res += numDistinct(S, i+1, T, j+1);
        return res;
    }
    
    int numDistinct(string S, string T) {
        return numDistinct(S, 0, T, 0);  
    }
};

// Top-down Dynamic Programming Version, time complexity O(nm), space complexity O(nm)
class Solution {
public:
    int numDistinct(string S, int i, string T, int j, vector<vector<int>> &mem) {
        if (j == T.size()) return 1;
        if (i == S.size()) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        int res = numDistinct(S, i+1, T, j, mem);
        if (S[i] == T[j]) res += numDistinct(S, i+1, T, j+1, mem);
        return mem[i][j] = res;
    }
    
    int numDistinct(string S, string T) {
        vector<vector<int>> mem(S.size(), vector<int>(T.size(), -1));
        return numDistinct(S, 0, T, 0, mem);  
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(nm), space complexity O(nm)
class Solution {
public:
    int numDistinct(string S, string T) {
        int M = S.size(), N = T.size();
        if (N == 0) return M;
        if (M==0 || M<N) return 0;
        vector<vector<int>> mem(M, vector<int>(N+1, 0));
        mem[M-1][N-1] = S.back()==T.back()? 1: 0;
        for (int i=M-2; i>=0; --i) {
            mem[i+1][N] = 1;
            for (int j=(i<N? i: N-1); j>=0; --j) {
                mem[i][j] = mem[i+1][j];
                if (S[i] == T[j]) mem[i][j] += mem[i+1][j+1];
            }
        }
        return mem[0][0];  
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, time complexity O(mn), space complexity O(n)
class Solution {
public:
    int numDistinct(string S, string T) {
        int M = S.size(), N = T.size();
        if (N == 0) return M;
        if (M==0 || M<N) return 0;
        vector<int> mem(N+1, 0);
        mem[N-1] = S.back()==T.back()? 1: 0;
        mem[N] = 1;
        for (int i=M-2; i>=0; --i) {
            for (int j=(i<N? i: N-1), next=mem[j+1], cur; j>=0; --j, next=cur) {
                cur = mem[j];
                if (S[i] == T[j]) mem[j] += next;
            }
        }
        return mem[0];  
    }
};