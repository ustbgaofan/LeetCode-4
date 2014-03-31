// Sudoku Solver 
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/


// Backtrack method, time complexity O(n^(m+1)), m is the number of spaces, and n is 9 here.
class Solution {
public:
    bool isValid(const vector<vector<char>> &board, int p, int q) {
        for (int i=0; i<9; ++i) {
            if (board[p][i]==board[p][q] && i!=q) return false;
        }
        for (int j=0; j<9; ++j) {
            if (board[j][q]==board[p][q] && j!=p) return false;
        }
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                int x = p/3*3 + i, y = q/3*3 + j;
                if (board[x][y]==board[p][q] && x!=p && y!=q) return false;
            }
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char>> &board, int x, int y) {
        for (int i=x; i<9; ++i) {
            for (int j=(i==x? y: 0); j<9; ++j) {
                if (board[i][j] == '.') {
                    for (int k=1; k<=9; ++k) {
                        board[i][j] = '0' + k;
                        if (isValid(board, i, j) && solveSudoku(board, i, j)) return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>> &board) {
        solveSudoku(board, 0, 0);
    }
};