// Maximal Rectangle
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

// Brute force, time O((mn)^3), space O(1)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), res = 0;
        for (int y1=0; y1<M; ++y1) {
            for (int y2=y1; y2<M; ++y2) {
                for (int x1=0; x1<N; ++x1) {
                    for (int x2=x1; x2<N; ++x2) {
                        if (isValid(matrix, x1, x2, y1, y2)) {
                            res = max(res, getArea(matrix, x1, x2, y1, y2));
                        }
                    }
                }
            }
        }
        return res;
    }
    
    bool isValid(const vector<vector<char>>& matrix, int x1, int x2, int y1, int y2) {
        for (int i=y1; i<=y2; ++i) {
            for (int j=x1; j<=x2; ++j) {
                if (matrix[i][j] == '0') return false;
            }
        }
        return true;
    }
    
    int getArea(const vector<vector<char>>& matrix, int x1, int x2, int y1, int y2) {
        return (x2-x1+1) * (y2-y1+1);
    }
};

// 1st Version, time complexity O(m*n^2), space complexity O(mn)
class Solution {
public:  
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), res = 0;
        vector<vector<pair<int,int>>> mem(M, vector<pair<int,int>>(N, pair<int,int>(0,0)));
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (matrix[i][j] == '0') continue;
                int x = j==0? 1: mem[i][j-1].first+1, y = i==0? 1: mem[i-1][j].second+1;
                mem[i][j] = make_pair(x, y);
                int minHeight = y;
                for (int k=j; k>j-x; --k) {
                    minHeight = min(minHeight, mem[i][k].second);
                    res = max(res, minHeight*(j-k+1));
                }
            }
        }
        return res;
    }
};

// 2nd Version based on Largest Rectangle in Histogram, time complexity O(mn), space complexity O(n)
class Solution {
public:
    int largestRectangleArea(const vector<int> &height) {
        stack<int> lbStk;  // left boundary stack
        int res = 0;
        for (int i=0; i<height.size(); ++i) {
            while (!lbStk.empty() && height[lbStk.top()]>=height[i]) {
                int h = height[lbStk.top()];
                lbStk.pop();
                int w = lbStk.empty()? i: i-lbStk.top()-1;
                res = max(res, w*h);
            }
            lbStk.push(i);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), res = 0;
        vector<int> height(N+1, 0);
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) height[j] = matrix[i][j]=='0'? 0: height[j]+1;
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
};
