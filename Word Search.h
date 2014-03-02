// Word Search
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


// time complexity O(mn * 4^(k-1)), extra space complexity O(k)
class Solution {
public:
    bool DFS(vector<vector<char>> &board, int row, int col, string &word, int i) {
        if (i+1 == word.size()) return true;
        char tmp = board[row][col];
        board[row][col] = '#';
        int m = board.size(), n = board[0].size();
        if (col > 0 && board[row][col-1]!='#' && board[row][col-1]==word[i+1] 
            && DFS(board,row,col-1,word,i+1)) return true;
        if (col+1<n && board[row][col+1]!='#' && board[row][col+1]==word[i+1] 
            && DFS(board,row,col+1,word,i+1)) return true;
        if (row > 0 && board[row-1][col]!='#' && board[row-1][col]==word[i+1] 
            && DFS(board,row-1,col,word,i+1)) return true;
        if (row+1<m && board[row+1][col]!='#' && board[row+1][col]==word[i+1] 
            && DFS(board,row+1,col,word,i+1)) return true;
        board[row][col] = tmp;
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j]==word[0] && DFS(board,i,j,word,0)) {
                    return true;
                }
            }
        }
        return false;
    }
};