// Divide Two Integers
/*
Divide two integers without using multiplication, division and mod operator.
*/

// Naive Version, Time Limit Exceeded, time complexity O(n), where n=dividend/divisor
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = false;
        if (dividend>0 && divisor<0 || dividend<0 && divisor>0) flag = true;
        if (dividend < 0) dividend = -dividend;  // overflow!
        if (divisor < 0) divisor = -divisor;  //overflow!
        int res = 0;  // may overflow, but is required by the return type
        while (dividend >= divisor) {
            dividend -= divisor;
            ++res;
        }
        return res = flag? -res: res;
    }
};

// Sophisticated Version, O((log(n))^2), where n=dividend/divisor
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = false;
        if (dividend>0 && divisor<0 || dividend<0 && divisor>0) flag = true;
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        int res = 0;  // may overflow, but is required by the return type 
        while (dividendll >= divisorll) {
            long long div = divisorll;
            int count = 1;
            while (div<<1 <= dividendll) {
                div <<= 1;
                count <<= 1;
            }
            dividendll -= div;
            res += count;
        }
        return res = flag? -res: res;
    }
};