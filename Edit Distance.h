// Edit Distance
/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/


// Recursive Version, Time Limit Exceeded 
/*
Insert   	A[1, lenA] B[2, lenB]
			A[2, lenA] B[1, lenB]
Delete		A[2, lenA] B[1, lenB]
			A[1, lenA] B[2, lenB]
Replace		A[2, lenA] B[2, lenB]
			A[2, lenA] B[2, lenB]
*/ 
class Solution {
public:
    int minDistance(const string &word1, const string &word2, int i, int j) {
	    int N = word1.size(), M = word2.size();
	    if (i==N || j==M) return max(N-i, M-j);  
	    if (word1[i] == word2[j]) return minDistance(word1, word2, i+1, j+1);
		int res = minDistance(word1, word2, i+1, j+1);
		res = min(res, minDistance(word1, word2, i, j+1));
		res = min(res, minDistance(word1, word2, i+1, j));
		return ++res; 
    }

    int minDistance(string word1, string word2) {
	    return minDistance(word1, word2, 0, 0);
    }
};

// Top-down Dynamic Programming Version 
class Solution {
public:
    int minDistance(const string &word1, const string &word2, int i, int j, vector<vector<int>> &mem) {
	    int N = word1.size(), M = word2.size();
	    if (i==N || j==M) return max(N-i, M-j);
	    if (mem[i][j] != -1) return mem[i][j];
	    if (word1[i] == word2[j]) return mem[i][j] = minDistance(word1, word2, i+1, j+1, mem);
		int res = minDistance(word1, word2, i+1, j+1, mem);
		res = min(res, minDistance(word1, word2, i, j+1, mem));
		res = min(res, minDistance(word1, word2, i+1, j, mem));
		return mem[i][j] = ++res;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> mem(word1.size(), vector<int>(word2.size(), -1));
	    return minDistance(word1, word2, 0, 0, mem);
    }
};

// Bottom-up Dynamic Programming Version
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        vector<vector<int>> mem(N+1, vector<int>(M+1));
        for (int i=0; i<=M; ++i) mem[0][i] = i; 
        for (int i=0; i<N; ++i) {
            mem[i+1][0] = i + 1;
            for (int j=0; j<M; ++j) {
                if (word1[i] == word2[j]) mem[i+1][j+1] = mem[i][j];
                else mem[i+1][j+1] = 1 + min(mem[i][j], min(mem[i][j+1], mem[i+1][j]));
            }
        }
	    return mem[N][M];
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, O(2M)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        vector<vector<int>> mem(2, vector<int>(M+1));
        for (int i=0; i<=M; ++i) mem[0][i] = i; 
        for (int i=0; i<N; ++i) {
            mem[(i+1)%2][0] = i + 1;
            for (int j=0; j<M; ++j) {
                if (word1[i] == word2[j]) mem[(i+1)%2][j+1] = mem[i%2][j];
                else mem[(i+1)%2][j+1] = 1 + min(mem[i%2][j], min(mem[i%2][j+1], mem[(i+1)%2][j]));
            }
        }
	    return mem[N%2][M];
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, O(M)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        vector<int> mem(M+1);
        for (int i=0; i<=M; ++i) mem[i] = i; 
        for (int i=0; i<N; ++i) {
            int backup = mem[0];
            mem[0] = i + 1;
            for (int j=0; j<M; ++j) {
                int tmp = mem[j+1];
                if (word1[i] == word2[j]) mem[j+1] = backup;
                else mem[j+1] = 1 + min(backup, min(mem[j+1], mem[j]));
                backup = tmp;
            }
        }
	    return mem[M];
    }
};