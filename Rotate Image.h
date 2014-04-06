// Rotate Image
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/


// Not In-place Version
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<vector<int>> tmp(matrix);
        int N = matrix.size();
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                matrix[j][N-i-1] = tmp[i][j];
            }
        }
    }
};

// In-place Version 1, (i,j) --> (j, n-i-1)
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int N = matrix.size();
        for (int i=0; i<N/2; ++i) {
            for (int j=i; j<N-1-i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[N-1-j][i];
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
                matrix[j][N-1-i] = t;
            }
        }
    }
};

// In-place Version 2, --> A^T --> 90C
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int N = matrix.size();
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};