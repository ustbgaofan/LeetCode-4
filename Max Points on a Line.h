// Max Points on a Line
/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// Naive Version (line view), only works without duplicates, time complexity O(n^3), space complexity O(1)
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int N = points.size(), res = 0;
		if (N < 3) return N;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                int count = 2;
                float s = points[i].x==points[j].x? INT_MAX: 1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                for (int k=j+1; k<N; ++k) {
                    float t = points[i].x==points[k].x? INT_MAX: 1.0*(points[i].y-points[k].y)/(points[i].x-points[k].x);
                    if (fabs(s-t) < 1e-5) ++count;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

// Advanced Version (line view), time complexity O(n^3), space complexity O(1)
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        enum LineType {POINT, VLINE, LINE}; 
        int N = points.size(), res = 0;
        if (N < 3) return N;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                LineType lineType;
                double a, b;
                if (points[i].x == points[j].x) {
                    lineType = points[i].y==points[j].y? POINT: VLINE;
                } else {
                    lineType = LINE;
                    a = 1.0*(points[j].y-points[i].y) / (points[j].x-points[i].x);
                    b = points[i].y - a*points[i].x;
                }
                int count = 2;
                for (int k=0; k<N; ++k) {
                    if (k==i || k==j) continue;
                    if (lineType == LINE) {
                        if (fabs(points[k].y - a*points[k].x - b) < 1e-8) ++count;
                    } else if (lineType == POINT) {
                        if (points[k].x==points[i].x && points[k].y==points[i].y) ++count;
                    } else {
                        if (points[k].x == points[i].x) ++count;
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

// Advanced Version (point view), time complexity O(n^2), space complexity O(n)
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int N = points.size(), res = 0;
		unordered_map<float, int> hash;
        for (int i=0; i<N; ++i) {
            hash.clear();
            int dup = 0;
            for (int j=0; j<N; ++j) {
                if (points[i].x==points[j].x && points[i].y==points[j].y) {
                    ++dup;
                    continue;
                }
                float s = points[i].x==points[j].x? INT_MAX: 1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                hash[s] = hash.find(s)!=hash.end()? ++hash[s]: 1;
            }
            res = max(res, dup); 
            for (unordered_map<float, int>::const_iterator it=hash.begin(); it!=hash.end(); ++it) {
                res = max(res, it->second+dup);
            }
        }
        return res;
    }
};