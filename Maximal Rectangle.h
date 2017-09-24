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
        for (int x1=0; x1<N; ++x1) {
            for (int y1=0; y1<M; ++y1) {
                for (int x2=x1; x2<N; ++x2) {
                    for (int y2=y1; y2<M; ++y2) {
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

// Based on Largest Rectangle in Histogram, time complexity O(mn), space complexity O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), res = 0;
        vector<int> v(N, 0);
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) matrix[i][j]=='1'? ++v[j]: v[j]=0;
            res = max(res, largestRectangleArea(v));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int res = 0;
        heights.push_back(0);
        for (int i=0; i<heights.size(); ) {
            if (stk.empty() || heights[i]>=heights[stk.top()]) {
                stk.push(i++);    
            } else {
                int cur = stk.top();
                stk.pop();
                res = max(res, heights[cur] * (stk.empty()? i : i-stk.top()-1));
            }
        }
        return res;
    }
};
