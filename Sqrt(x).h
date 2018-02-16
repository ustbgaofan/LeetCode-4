// Sqrt(x) 
/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
*/

// time O(logx), space O(1)
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, res;
        while (l <= r) {
            long long m = l + (r-l)/2;  // due to below reason
            long long t = m * m;  // overflow!
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
