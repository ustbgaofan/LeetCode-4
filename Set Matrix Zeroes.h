// Set Matrix Zeroes 
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/


// Brute force, time O(mn(m+n)), space O(mn)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<bool>> v(M, vector<bool>(N, false));
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (matrix[i][j] == 0) {
                    for (int k=0; k<N; ++k) v[i][k] = true;
                    for (int k=0; k<M; ++k) v[k][j] = true;
                }
            }
        }
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (v[i][j]) matrix[i][j] = 0;
            }
        }
    }
};

// Row + col, time O(mn), space O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<bool> row(M, false), col(N, false);
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (matrix[i][j] == 0) row[i] = col[j] = true;
            }
        }
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};
 
// Store information in first row and first column, time O(mn), space O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        bool row = false, col = false;
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row = true;
                    if (j == 0) col = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i=1; i<M; ++i) {
            for (int j=1; j<N; ++j) {
                if (matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j] = 0;
            }
        }
        if (row) {
            for (int i=0; i<N; ++i) matrix[0][i] = 0;
        }
        if (col) {
            for (int i=0; i<M; ++i) matrix[i][0] = 0;
        }
    }
};
