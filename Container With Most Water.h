// Container With Most Water 
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

// Time Limit Exceeded Version, O(n^2)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0, size = height.size();
        for (int i=0; i<size; ++i) {
            for (int j=i+1; j<size; ++j) {
                res = max(res, (j-i) * min(height[i],height[j]));
            }
        }
        return res;
    }
};

// Time Limit Exceeded Version, skipping some tests through current maxArea, O(n^2)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0, size = height.size();
        for (int i=0; i<size; ++i) {
            if (height[i] == 0) continue;
            for (int j=i+ceil(res*1.0/height[i]); j<size; ++j) {
                if (height[j] < height[i]) continue;
                res = max(res, (j-i) * min(height[i],height[j]));
            }
        }
        return res;
    }
};

// One Pass Version, O(n)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0, size = height.size();
        for (int i=0, j=size-1; i<j;) {
            int minHeight = min(height[i], height[j]);
            res = max(res, (j-i)*minHeight);
            if (height[i] <= minHeight)
                while (++i<j && height[i]<=minHeight);
            if (height[j] <= minHeight)
                while (i<--j && height[j]<=minHeight);
        }
        return res;
    }
};