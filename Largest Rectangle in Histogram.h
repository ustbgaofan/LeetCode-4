// Largest Rectangle in Histogram
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/


// Brute force, time O(n^2), space O(1)
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

// time O(n), space O(n)
// O(n^2) combinations, but only O(n) useful values, so test each bar's largest potential area.
// use stack to record left boundary. only increasing h in stk. if [cur]<[stk.top], trigger calculation.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int res = 0;
        heights.push_back(0);  // corner case, to trigger the final calculation!
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
