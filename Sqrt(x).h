// Sqrt(x) 
/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, res;
        while (l <= r) {
            long long m = l + (r-l)/2;
            long long t = m * m;
            if (t == x) return m;
            if (t < x) {
                res = m;
                l = m + 1;
            }
            if (t > x) r = m - 1;
        }
        return res;
    }
};
