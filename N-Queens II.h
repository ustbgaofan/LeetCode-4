// N-Queens II
/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


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
    
    int DFS(int n, vector<string> &path) {
        if (path.size() == n) return 1;
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (!isValid(path, n, i)) continue;
            string line(n, '.');
            line[i] = 'Q';
            path.push_back(line);
            res += DFS(n, path);
            path.pop_back();
        }
        return res;
    }
    
    int totalNQueens(int n) {
        vector<string> path;
        return DFS(n, path);
    }
};

// Advanced DFS Version with Bit Manipulation, size of board must be within INT's number of bits, time complexity O(n^n), 
class Solution {
public:
    int BitDFS(int n, int row, int ld, int rd) {
        if (row == (1<<n)-1) return 1;
        int res = 0;
        for (int i=n-1, cur=1, avail=row|ld|rd; i>=0; --i, cur<<=1) {
            if (avail & cur) continue;
            res += BitDFS(n, row|cur, (ld|cur)>>1, (rd|cur)<<1);
        }
        return res;
    }
    
    int totalNQueens(int n) {
        return BitDFS(n, 0, 0, 0);
    }
};

// Iterative Version, time complexity O(n^(n+1)) 
class Solution {
public:
    bool isValid(vector<int> &board, int row, int col) {
        for (int i=row-1, k=1; i>=0; --i, ++k) {
            if (board[i]==col || abs(row-i)==abs(col-board[i])) {
                return false;
            }
        }
        return true;
    }
    
    int totalNQueens(int n) {
        int res = 0;
        vector<int> board(n, -1);
        for (int i=0; i<n && i>=0; ++i) {
            int j = board[i] + 1;
            for (; j<n; ++j) {
                if (!isValid(board, i,j)) continue;
                board[i] = j;
                break;
            }
            if (j==n || i==n-1) {
                board[i] = -1;
                i -= 2;
                if (j == n) continue;
                else ++res;
            }
        }
        return res;
    }
};