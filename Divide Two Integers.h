// Divide Two Integers
/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

// Brute force, time O(n), where n=dividend/divisor, space O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0 || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
        bool sign = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        long long dvd = labs(dividend), dvs = labs(divisor), res = 0;  // (INT_MIN, 1)
        while (dvd >= dvs) {
            dvd -= dvs;
            ++res;
        }
        return res = sign? -res: res;
    }
};

// Bit-manipulation, time O(logn), where n=dividend/divisor, space O(1)
// 2^k * dvs = dvd;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0 || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
        bool sign = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        long long dvd = labs(dividend), dvs = labs(divisor), res = 0;  // (INT_MIN, 1)
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp<<1)){
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return res = sign? -res: res;
    }
};
