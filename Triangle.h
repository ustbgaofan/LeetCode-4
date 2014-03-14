// Triangle 
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/


// Recursive Version, Time Limit Exceeded
class Solution {
public:
    int DFS(vector<vector<int>> &triangle, int depth, int begin) {
        if (depth+1 == triangle.size()) return triangle[depth][begin];
        return triangle[depth][begin] + min(DFS(triangle, depth+1, begin), DFS(triangle, depth+1, begin+1));
    }
    
    int minimumTotal(vector<vector<int> > &triangle) {
        return DFS(triangle, 0, 0);
    }
};

// Top-down Dynamic Programming Version, space complexity O(n^2) 
class Solution {
public:
    int DFS(vector<vector<int>> &triangle, int depth, int begin, vector<vector<int>> &mem) {
        if (mem[depth][begin] != INT_MAX) return mem[depth][begin];
        if (depth+1 == triangle.size()) return mem[depth][begin] = triangle[depth][begin];
        mem[depth][begin] = triangle[depth][begin];
        mem[depth][begin] += min(DFS(triangle, depth+1, begin, mem), DFS(triangle, depth+1, begin+1, mem));
        return mem[depth][begin];
    }
    
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int>> mem;
        for (int i=0; i<triangle.size(); ++i) mem.push_back(vector<int>(i+1, INT_MAX));
        return DFS(triangle, 0, 0, mem);
    }
};

// Bottom-up Dynamic Programming Version, space complexity O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int>> mem(triangle);
        for (int i=triangle.size()-2; i>=0; --i) {
            for (int j=0; j<mem[i].size(); ++j) {
                mem[i][j] += min(mem[i+1][j], mem[i+1][j+1]);
            }
        }
        return mem[0][0];
    }
};

// Space Optimized Bottom-up Dynamic Programming Version, space complexity O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> mem(triangle.back());
        for (int i=triangle.size()-2; i>=0; --i) {
            for (int j=0; j<triangle[i].size(); ++j) {
                mem[j] = triangle[i][j] + min(mem[j], mem[j+1]);
            }
        }
        return mem[0];
    }
};