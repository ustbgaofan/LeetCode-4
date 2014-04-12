// Sqrt(x) 
/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int sqrt(int x) {
        int l = 0, r = (x>>1) + 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            long long t = m;  // !!!wrong: t = m*m
            t *= m;
            if (t > x) r = m - 1;
            else if (t < x) l = m + 1;
            else return m;
        }
        return r;
    }
};