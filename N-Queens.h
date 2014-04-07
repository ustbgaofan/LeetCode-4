// N-Queens
/*
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/


// Naive DFS Version, time complexity O(n^(n+1))
class Solution {
public:
    bool isValid(vector<string> &path, int n, int pos) {
        int M = path.size();
        for (int i=M-1, k=1; i>=0; --i, ++k) {
            if (path[i][pos] == 'Q') return false;
            if (pos-k>=0 && path[i][pos-k]=='Q') return false;
            if (pos+k<n && path[i][pos+k]=='Q') return false;
        }
        return true;
    }
    
    void DFS(int n, vector<vector<string>> &res, vector<string> &path) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        for (int i=0; i<n; ++i) {
            if (!isValid(path, n, i)) continue;
            string line(n, '.');
            line[i] = 'Q';
            path.push_back(line);
            DFS(n, res, path);
            path.pop_back();
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path;
        DFS(n, res, path);
        return res;
    }
};

// Advanced DFS Version with Bit Manipulation, size of board must be within INT's number of bits, time complexity O(n^n), 
class Solution {
public:
    void BitDFS(int n, int row, int ld, int rd, vector<vector<string>> &res, vector<string> &path) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        for (int i=n-1, cur=1, avail=row|ld|rd; i>=0; --i, cur<<=1) {
            if (avail & cur) continue;
            string line(n, '.');
            line[i] = 'Q';
            path.push_back(line);
            BitDFS(n, row|cur, (ld|cur)>>1, (rd|cur)<<1, res, path);
            path.pop_back();
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path;
        BitDFS(n, 0, 0, 0, res, path);
        return res;
    }
};