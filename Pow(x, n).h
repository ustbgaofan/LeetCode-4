// Pow(x, n)
/*
Implement pow(x, n).
*/

// Time Limit Exceeded, time O(n), space O(1) 
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int m = abs(n);
        while (m--) {
            res *= x;
        }
        if (n < 0) res = 1 / res;
        return res;
    }
};

// time O(logn), space O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1 / power(x, -n);
        return power(x, n);
    }
    
    double power(double x, int n) {
        if (n == 0) return 1;
        double h = power(x, n/2);
        return n%2==0 ? h*h : h*h*x;
    }
};
