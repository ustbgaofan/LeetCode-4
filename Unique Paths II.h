// Unique Paths II
/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/


// Recursive Version, Time Limit Exceeded  
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid, int i, int j) {
        if (obstacleGrid[i][j] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid.back().size();
        if (i+1==m && j+1==n) return 1;
        int res = (i+1) < m? uniquePathsWithObstacles(obstacleGrid, i+1, j): 0;
        res += (j+1) < n? uniquePathsWithObstacles(obstacleGrid, i, j+1): 0;
        return res;
    }
    
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        return uniquePathsWithObstacles(obstacleGrid, 0, 0);
    }
};

// Top-down Dynamic Programming Version 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &mem) {
        if (mem[i][j] >= 0) return mem[i][j];
        if (obstacleGrid[i][j] == 1) return mem[i][j] = 0;
        int m = obstacleGrid.size(), n = obstacleGrid.back().size();
        if (i+1==m && j+1==n) return mem[i][j] = 1;
        mem[i][j] = (i+1) < m? uniquePathsWithObstacles(obstacleGrid, i+1, j, mem): 0;
        mem[i][j] += (j+1) < n? uniquePathsWithObstacles(obstacleGrid, i, j+1, mem): 0;
        return mem[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int>> mem(obstacleGrid.size(), vector<int>(obstacleGrid.back().size(), -1));
        return uniquePathsWithObstacles(obstacleGrid, 0, 0, mem);
    }
};

// Bottom-up Dynamic Programming Version
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.back().size();
        if (obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> mem(m, vector<int>(n, -1));
        mem[m-1][n-1] = 1;
        for (int i=n-2; i>=0; --i) {
            mem[m-1][i] = obstacleGrid[m-1][i]==1? 0: mem[m-1][i+1];
        }
        for (int i=m-2; i>=0; --i) {
            mem[i][n-1] = obstacleGrid[i][n-1]==1? 0: mem[i+1][n-1];
            for (int j=n-2; j>=0; --j) {
                mem[i][j] = obstacleGrid[i][j]==1? 0: mem[i+1][j]+mem[i][j+1];
            }
        }
        return mem[0][0];
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, O(2k)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.back().size();
        if (obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> mem(2, vector<int>(n, -1));
        mem[(m-1)%2][n-1] = 1;
        for (int i=n-2; i>=0; --i) {
            mem[(m-1)%2][i] = obstacleGrid[m-1][i]==1? 0: mem[(m-1)%2][i+1];
		}
        for (int i=m-2; i>=0; --i) {
            mem[i%2][n-1] = obstacleGrid[i][n-1]==1? 0: mem[(i+1)%2][n-1];
            for (int j=n-2; j>=0; --j) {
                mem[i%2][j] = obstacleGrid[i][j]==1? 0: mem[(i+1)%2][j]+mem[i%2][j+1];
            }
        }
        return mem[0][0];
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, O(k)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.back().size();
        if (obstacleGrid[m-1][n-1] == 1) return 0;
        vector<int> mem(n, -1);
        mem[n-1] = 1;
        for (int i=n-2; i>=0; --i) {
            mem[i] = obstacleGrid[m-1][i]==1? 0: mem[i+1];
		}
        for (int i=m-2; i>=0; --i) {
            mem[n-1] = obstacleGrid[i][n-1]==1? 0: mem[n-1];
            for (int j=n-2; j>=0; --j) {
                mem[j] = obstacleGrid[i][j]==1? 0: mem[j]+mem[j+1];
            }
        }
        return mem[0];
    }
};