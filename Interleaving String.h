// Interleaving String
/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/


// Recursive Version, Time Limit Exceeded 
class Solution {
public:
    bool isInterleave(const string &s1, int i, const string &s2, int j, const string &s3, int k) {
	    int M = s1.size(), N = s2.size(), P = s3.size();
	    if (P - k != M - i + N - j) return false;
	    if (k == P) return true;
	    if (i<M && s1[i]==s3[k] && isInterleave(s1, i+1, s2, j, s3, k+1)) return true;
	    if (j<N && s2[j]==s3[k] && isInterleave(s1, i, s2, j+1, s3, k+1)) return true;
	    return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
	    return isInterleave(s1, 0, s2, 0, s3, 0);
    }
};

// Top-down Dynamic Programming Version, time complexity O(mn), space complexity O(mn)
class Solution {
public:
    bool isInterleave(const string &s1, int i, const string &s2, int j, const string &s3, int k, vector<vector<int>> &mem) {
	    if (mem[i][j] != -1) return mem[i][j];
	    int M = s1.size(), N = s2.size(), P = s3.size();
	    if (P - k != M - i + N - j) return mem[i][j] = false;
	    if (k == P) return mem[i][j] = true;
	    if (i<M && s1[i]==s3[k] && isInterleave(s1, i+1, s2, j, s3, k+1, mem)) return mem[i][j] = true;
	    if (j<N && s2[j]==s3[k] && isInterleave(s1, i, s2, j+1, s3, k+1, mem)) return mem[i][j] = true;
	    return mem[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> mem(s1.size()+1, vector<int>(s2.size()+1, -1));
	    return isInterleave(s1, 0, s2, 0, s3, 0, mem);
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(mn), space complexity O(mn)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size(), P = s3.size();
        vector<vector<bool>> mem(M+1, vector<bool>(N+1));
        mem[M][N] = M+N == P;
        for (int j=N-1; j>=0; --j) mem[M][j] = mem[M][j+1] && s2[j]==s3[M+j];
        for (int i=M-1; i>=0; --i) {
            mem[i][N] = mem[i+1][N] && s1[i]==s3[N+i];
            for (int j=N-1; j>=0; --j) {
                mem[i][j] = s1[i]==s3[i+j] && mem[i+1][j] || s2[j]==s3[i+j] && mem[i][j+1];
            }
        }
	    return mem[0][0];
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, time complexity O(mn), space complexity O(n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size(), P = s3.size();
        vector<bool> mem(M+1);
        mem[N] = M+N == P;
        for (int j=N-1; j>=0; --j) mem[j] = mem[j+1] && s2[j]==s3[M+j];
        for (int i=M-1; i>=0; --i) {
            mem[N] = mem[N] && s1[i]==s3[N+i];
            for (int j=N-1; j>=0; --j) {
                mem[j] = s1[i]==s3[i+j] && mem[j] || s2[j]==s3[i+j] && mem[j+1];
            }
        }
	    return mem[0];
    }
};