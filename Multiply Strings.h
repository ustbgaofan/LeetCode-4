// Multiply Strings
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/


class Solution {
public:
    string multiply(string num1, string num2) {
        int M = num1.size(), N = num2.size();
        string res(M+N, '0');
        for (int i=N-1; i>=0; --i) {
            int carry = 0;
            for (int j=M-1; j>=0; --j) {
                int tmp = (num2[i]-'0') * (num1[j]-'0') + carry + (res[i+j+1]-'0');
                carry = tmp / 10;
                res[i+j+1] = tmp % 10 + '0';
            }
            if (carry > 0) res[i] = carry + '0';
        }
        while (res[0]=='0' && res.size()>1) res.erase(0, 1);
        return res;
    }
};
