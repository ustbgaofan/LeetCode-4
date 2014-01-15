// Valid Sudoku
/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
*/


// Version 1, using set to judge duplicates
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i=0; i<9; ++i) 
            if (!isValid(board[i])) return false;
        for (int i=0; i<9; ++i) {
            vector<char> v;
            for (int j=0; j<9; ++j) 
                v.push_back(board[j][i]);
            if (!isValid(v)) return false;
        }
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                vector<char> v;
                for (int p=0; p<3; ++p)
                    for (int q=0; q<3; ++q)
                        v.push_back(board[i*3+p][j*3+q]);    
                if (!isValid(v)) return false;
            }
        }
        return true;
    }
    
    bool isValid(const vector<char> &v) {
        unordered_set<char> hash;
        int size = v.size();
        for (int i=0; i<size; ++i) {
            if (v[i] == '.') continue;
            if (hash.find(v[i]) != hash.end()) return false;
            else hash.insert(v[i]);
        }
        return true;
    }
};

// Version 2, judge duplicates through value mapping  
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool visited[9];
        for (int i=0; i<9; ++i) {
            memset(visited, 0, sizeof(visited));
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.') continue;
                int k = board[i][j] - '1';
                if (visited[k]) return false;
                else visited[k] = true;
            }
        }
        for (int i=0; i<9; ++i) {
            memset(visited, 0, sizeof(visited));
            for (int j=0; j<9; ++j) {
                if (board[j][i] == '.') continue;
                int k = board[j][i] - '1';
                if (visited[k]) return false;
                else visited[k] = true;
            }
        }
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                memset(visited, 0, sizeof(visited));
                for (int p=0; p<3; ++p) {
                    for (int q=0; q<3; ++q) {
                        if (board[i*3+p][j*3+q] == '.') continue;
                        int k = board[i*3+p][j*3+q] - '1';
                        if (visited[k]) return false;
                        else visited[k] = true;
                    }
                }
            }
        }
        return true;
    }
};