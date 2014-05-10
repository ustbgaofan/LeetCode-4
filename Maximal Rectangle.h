// Maximal Rectangle
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/


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
