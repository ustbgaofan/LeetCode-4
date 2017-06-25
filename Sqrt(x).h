// Sqrt(x) 
/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x; // r = x/2+1
        while (l <= r) {
            int m = l + (r-l)/2;
            long long t = m;  // long long t = m*m (wrong!)
            t *= m;
            if (t > x) r = m-1;
            if (t < x) l = m+1;
            if (t == x) return m;
        }
        return r;
    }
};
