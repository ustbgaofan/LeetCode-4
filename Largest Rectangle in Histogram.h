// Largest Rectangle in Histogram
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/


// Naive Version, Time Limit Exceeded, time O(n^2), space O(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size(), res = 0;
        for (int i=0; i<N; ++i) {
            int h = heights[i];
            for (int j=i; j<N; ++j) {
                h = min(h, heights[j]);
                res = max(res, (j-i+1) * h);
            }
        }
        return res;
    }
};

// Naive Version with Filtering, time complexity O(n^2), space complexity O(1)
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int N = height.size(), res = 0;
        for (int i=0; i<N; ++i) {
            if (i<N-1 && height[i]<=height[i+1]) continue;
            int minHeight = height[i];
            for (int j=i; j>=0; --j) {
                minHeight = min(minHeight, height[j]);
                res = max(res, (i-j+1)*minHeight);
            }
        }
        return res;
    }
};

// Left Boundary Recording, time complexity O(n), space complexity O(n)
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> lbStk;  // left boundary stack
        int res = 0;
        height.push_back(0);
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
};
