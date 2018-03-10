// Rotate Image
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/


// Non In-place, time O(n^2), space O(n^2)
// (i,j) --> (j, n-i-1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> t(matrix);
        int N = matrix.size();
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                matrix[j][N-i-1] = t[i][j];
            }
        }
    }
};

// In-place, time O(n^2), space O(1)
/* clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=i+1; j<matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
