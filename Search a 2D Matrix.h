// Search a 2D Matrix 
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/


// Naive Version, passed!
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};

// Imbedded Binary Search Version, runtime complexity O(logm)+O(logn)=O(log(mn))
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int u = 0, d = m - 1; 
        while (u <= d) {
            int mid = (u + d) / 2;
            if (target > matrix[mid][n-1]) u = mid + 1;    
            else if (target < matrix[mid][0]) d = mid - 1;
            else {
                int l = 0, r = n - 1;
                while (l <= r) {
                    int p = (l + r) / 2;
                    if (target > matrix[mid][p]) l = p + 1;
                    else if (target < matrix[mid][p]) r = p - 1;
                    else return true;
                }
                return false;
            }
        }
        return false;
    }
};

// 1D Binary Search Version, runtime complexity O(log(mn))
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1; 
        while (l <= r) {
            int mid = (l + r) / 2, midVal = matrix[mid/n][mid%n];
            if (target > midVal) l = mid + 1;    
            else if (target < midVal) r = mid - 1;
            else return true;
        }
        return false;
    }
};