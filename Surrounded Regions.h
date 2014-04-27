// Surrounded Regions
/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/


// DFS, Runtime Error, time complexity O(mn), space complexity O(mn)
class Solution {
public:
    void DFS(vector<vector<char>> &board, int row, int col) {
        int M = board.size(), N = board[0].size();
        if (row==M || row==-1 || col==-1 || col==N || board[row][col]!='O') return;
        board[row][col] = 'V';
        DFS(board, row-1, col);
        DFS(board, row, col+1);
        DFS(board, row+1, col);
        DFS(board, row, col-1);
    }
    
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        int M = board.size(), N = board[0].size();
        for (int j=0; j<N; ++j) {
            if (board[0][j] == 'O') DFS(board, 0, j);
            if (board[M-1][j] == 'O') DFS(board, M-1, j);
        }
        for (int i=0; i<M; ++i) {
            if (board[i][N-1] == 'O') DFS(board, i, N-1);
            if (board[i][0] == 'O') DFS(board, i, 0);
        }
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                board[i][j] = board[i][j]=='V'? 'O': 'X';
            }
        }
    }
};

// BFS, time complexity O(mn), space complexity O(mn)
class Solution {
public:
    void BFS(vector<vector<char>> &board, int row, int col) {
        int M = board.size(), N = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            if (r==M || r==-1 || c==-1 || c==N || board[r][c]!='O') continue;
            board[r][c] = 'V';
            q.push(make_pair(r-1, c));
            q.push(make_pair(r, c+1));
            q.push(make_pair(r+1, c));
            q.push(make_pair(r, c-1));
        }
    }
    
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        int M = board.size(), N = board[0].size();
        for (int j=0; j<N; ++j) {
            if (board[0][j] == 'O') BFS(board, 0, j);
            if (board[M-1][j] == 'O') BFS(board, M-1, j);
        }
        for (int i=0; i<M; ++i) {
            if (board[i][N-1] == 'O') BFS(board, i, N-1);
            if (board[i][0] == 'O') BFS(board, i, 0);
        }
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                board[i][j] = board[i][j]=='V'? 'O': 'X';
            }
        }
    }
};