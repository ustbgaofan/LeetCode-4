// Edit Distance
/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/


// Recursive
class Solution {
public:
    int minDistance(string word1, string word2) {
        return DFS(word1, word2, 0, 0);
    }
    
    int DFS(const string& w1, const string& w2, int i, int j) {
        int M = w1.size(), N = w2.size();
        if (i==M || j==N) return max(M-i, N-j);
        if (w1[i] == w2[j]) return DFS(w1, w2, i+1, j+1);
        int res = DFS(w1, w2, i, j+1);
        res = min(res, DFS(w1, w2, i+1, j));
        res = min(res, DFS(w1, w2, i+1, j+1));
        return ++res;
    }
};

// Top-down Dynamic Programming, time O(MN), space O(MN) 
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> m(word1.size(), vector<int>(word2.size(), -1));
        return DFS(word1, word2, 0, 0, m);
    }
    
    int DFS(const string& w1, const string& w2, int i, int j, vector<vector<int>>& m) {
        int M = w1.size(), N = w2.size();
        if (i==M || j==N) return max(M-i, N-j);
        if (m[i][j] != -1) return m[i][j];
        if (w1[i] == w2[j]) return DFS(w1, w2, i+1, j+1, m);
        int res = DFS(w1, w2, i, j+1, m);
        res = min(res, DFS(w1, w2, i+1, j, m));
        res = min(res, DFS(w1, w2, i+1, j+1, m));
        return m[i][j] = ++res;
    }
};

// Bottom-up Dynamic Programming, time O(MN), space O(MN) 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int>> m(M+1, vector<int>(N+1, 0));
        for (int i=0; i<=N; ++i) m[0][i] = i;
        for (int i=1; i<=M; ++i) {
            m[i][0] = i;
            for (int j=1; j<=N; ++j) {
                m[i][j] = word1[i-1]==word2[j-1]? 
                    m[i-1][j-1]: 1+min(m[i-1][j-1], min(m[i-1][j], m[i][j-1]));
            }
        }
        return m[M][N];
    }
};

// Space-optimized Bottom-up Dynamic Programming, time O(MN), space O(2N) 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int>> m(2, vector<int>(N+1, 0));
        for (int i=0; i<=N; ++i) m[0][i] = i;
        for (int i=1; i<=M; ++i) {
            m[i%2][0] = i;
            for (int j=1; j<=N; ++j) {
                m[i%2][j] = word1[i-1]==word2[j-1]?  
                    m[(i-1)%2][j-1]: 1+min(m[(i-1)%2][j-1], min(m[(i-1)%2][j], m[i%2][j-1]));
            }
        }
        return m[M%2][N];
    }
};

// Space-optimized Bottom-up Dynamic Programming, time O(MN), space O(N) 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        vector<int> m(N+1, 0);
        for (int i=0; i<=N; ++i) m[i] = i;
        for (int i=1; i<=M; ++i) {
            int backup = m[0];
            m[0] = i;
            for (int j=1; j<=N; ++j) {
                int t = m[j];
                m[j] = word1[i-1]==word2[j-1]? backup: 1+min(backup, min(m[j], m[j-1]));
                backup = t;
            }
        }
        return m[N];
    }
};
