// Minimum Path Sum
/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/


// Recursive Version, Time Limit Exceeded  
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid, int i, int j) {
        int high = grid.size(), len = grid.back().size();
        if (i==high-1 && j==len-1) return grid[i][j];
        int res = grid[i][j], sum1 = INT_MAX, sum2 = INT_MAX;
        if (i+1<high && j<len) sum1 = minPathSum(grid, i+1, j);
        if (i<high && j+1<len) sum2 = minPathSum(grid, i, j+1);
        return res + min(sum1, sum2);
    }
    
    int minPathSum(vector<vector<int> > &grid) {
        return minPathSum(grid, 0, 0);    
    }
};

// Top-down Dynamic Programming Version
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &mem) {
        if (mem[i][j] > 0) return mem[i][j];
        int high = grid.size(), len = grid.back().size();
        if (i==high-1 && j==len-1) return mem[i][j] = grid[i][j];
        int res = grid[i][j], sum1 = INT_MAX, sum2 = INT_MAX;
        if (i+1<high && j<len) sum1 = minPathSum(grid, i+1, j, mem);
        if (i<high && j+1<len) sum2 = minPathSum(grid, i, j+1, mem);
        return mem[i][j] = res + min(sum1, sum2);
    }
    
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid.back().size(), 0));
        return minPathSum(grid, 0, 0, mem);    
    }
};

// Bottom-up Dynamic Programming Version
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int high = grid.size(), len = grid.back().size(); 
        vector<vector<int>> mem(high, vector<int>(len, 0));
        mem[high-1][len-1] = grid[high-1][len-1];
        for (int i=len-2; i>=0; --i) {
            mem[high-1][i] = grid[high-1][i] + mem[high-1][i+1];
        }
        for (int i=high-2; i>=0; --i) {
            mem[i][len-1] = grid[i][len-1] + mem[i+1][len-1];
            for (int j=len-2; j>=0; --j) {
                mem[i][j] = grid[i][j] + min(mem[i+1][j], mem[i][j+1]);
            }
        }
        return mem[0][0];    
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, O(2k)
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int high = grid.size(), len = grid.back().size(); 
        vector<vector<int>> mem(2, vector<int>(len, 0));
        mem[(high-1)%2][len-1] = grid[high-1][len-1];
        for (int i=len-2; i>=0; --i) {
            mem[(high-1)%2][i] = grid[high-1][i] + mem[(high-1)%2][i+1];
        }
        for (int i=high-2; i>=0; --i) {
            mem[i%2][len-1] = grid[i][len-1] + mem[(i+1)%2][len-1];
            for (int j=len-2; j>=0; --j) {
                mem[i%2][j] = grid[i][j] + min(mem[(i+1)%2][j], mem[i%2][j+1]);
            }
        }
        return mem[0][0];    
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, O(k)
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int high = grid.size(), len = grid.back().size(); 
        vector<int> mem(len, 0);
        mem[len-1] = grid[high-1][len-1];
        for (int i=len-2; i>=0; --i) {
            mem[i] = grid[high-1][i] + mem[i+1];
        }
        for (int i=high-2; i>=0; --i) {
            mem[len-1] = grid[i][len-1] + mem[len-1];
            for (int j=len-2; j>=0; --j) {
                mem[j] = grid[i][j] + min(mem[j], mem[j+1]);
            }
        }
        return mem[0];    
    }
};