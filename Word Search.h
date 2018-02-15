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


// time O(mn * 4^(k-1)), space O(k)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j]==word[0] && DFS(board, word, 1, i, j)) return true;
            }
        }
        return false;
    }
    
    bool DFS(vector<vector<char>>& board, const string& word, int i, int r, int c) {
        if (i == word.size()) return true;
        char t = board[r][c];
        board[r][c] = '#';
        if (r>0 && board[r-1][c]==word[i] && DFS(board, word, i+1, r-1, c)) { board[r][c] = t; return true; }
        if (c+1<board[r].size() && board[r][c+1]==word[i] && DFS(board, word, i+1, r, c+1)) { board[r][c] = t; return true; }
        if (r+1<board.size() && board[r+1][c]==word[i] && DFS(board, word, i+1, r+1, c)) { board[r][c] = t; return true; }
        if (c>0 && board[r][c-1]==word[i] && DFS(board, word, i+1, r, c-1)) { board[r][c] = t; return true; }
        board[r][c] = t;
        return false;
    }
};
