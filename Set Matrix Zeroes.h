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


// Version 1, space complexity O(mn)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<pair<int, bool>>> tmpMatrix(m, 
            vector<pair<int,bool>>(n, pair<int,bool>(0,false)));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                tmpMatrix[i][j].first = matrix[i][j];
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == 0) {
                    for (int k=0; k<n; ++k) tmpMatrix[i][k].second = true;
                    for (int k=0; k<m; ++k) tmpMatrix[k][j].second = true;
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (tmpMatrix[i][j].second) matrix[i][j] = 0;
            }
        }
    }
};

// Version 2, space complexity O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false), col(n, false);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == 0) row[i] = col[j] = true;
            }
        }
        for (int i=0; i<row.size(); ++i) {
            if (row[i]) {
                for (int j=0; j<n; ++j) matrix[i][j] = 0;
            }
        }
        for (int j=0; j<col.size(); ++j) {
            if (col[j]) {
                for (int i=0; i<m; ++i) matrix[i][j] = 0;
            }
        }
    }
};
 
// Version 3, store information in first row and first column, without extra space
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, col = false;
        for (int i=0; i<n; ++i) {
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        }
        for (int i=0; i<m; ++i) {
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        }
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (matrix[i][j] == 0) 
                    matrix[0][j] = matrix[i][0] = 0;
            }
        }
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (matrix[0][j]==0 || matrix[i][0]==0) 
                    matrix[i][j] = 0;
            }
        }
        if (row) {
            for (int i=0; i<n; ++i) matrix[0][i] = 0;
        }
        if (col) {
            for (int i=0; i<m; ++i) matrix[i][0] = 0;
        }
    }
};