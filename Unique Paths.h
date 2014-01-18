// Unique Paths
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/


// Recursive Version, Time Limit Exceeded 
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==1 || n==1) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};

// Top-down Dynamic Programming Version 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **mem = new int*[m];
        for (int i=0; i<m; ++i) {
            mem[i] = new int[n];
            memset(mem[i], 0, sizeof(int)*n);
        }
        int res = uniquePaths(m, n, mem);
        for (int i=0; i<m; ++i) delete[] mem[i];
        delete[] mem;
        return res;
    }
    
    int uniquePaths(int m, int n, int **mem) {
        if (mem[m-1][n-1]) return mem[m-1][n-1];
        if (m==1 || n==1) mem[m-1][n-1] = 1;
        else mem[m-1][n-1] = uniquePaths(m-1, n, mem) + uniquePaths(m, n-1, mem);
        return mem[m-1][n-1];
    }
};

// Bottom-up Dynamic Programming Version 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **mem = new int*[m];
        for (int i=0; i<m; ++i) {
            mem[i] = new int[n];
            memset(mem[i], 0, sizeof(int)*n);
        }
        for (int i=0; i<m; ++i) mem[i][0] = 1;
        for (int i=0; i<n; ++i) mem[0][i] = 1;
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                mem[i][j] = mem[i-1][j] + mem[i][j-1];
            }
        }
        int res = mem[m-1][n-1];
        for (int i=0; i<m; ++i) delete[] mem[i];
        delete[] mem;
        return res;
    }
};

// Space Optimized Bottom-up Dynamic Programming Version 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **mem = new int*[2];
        for (int i=0; i<2; ++i) {
            mem[i] = new int[n];
            memset(mem[i], 0, sizeof(int)*n);
        }
        for (int i=0; i<2; ++i) mem[i][0] = 1;
        for (int i=0; i<n; ++i) mem[0][i] = 1;
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                mem[i%2][j] = mem[(i-1)%2][j] + mem[i%2][j-1];
            }
        }
        int res = mem[(m-1)%2][n-1];
        for (int i=0; i<2; ++i) delete[] mem[i];
        delete[] mem;
        return res;
    }
};