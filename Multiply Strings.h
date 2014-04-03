// Multiply Strings
/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/


class Solution {
public:
    string multiply(string num1, string num2) {
        int N = num1.size(), M = num2.size();
        string res(N+M, '0');
        for (int i=M-1; i>=0; --i) {
            int carry = 0;
            for (int j=N-1; j>=0; --j) {
                int tmp = (num2[i]-'0') * (num1[j]-'0') + (res[i+1+j]-'0') + carry;
                carry = tmp / 10;
                tmp %= 10;
                res[i+1+j] = tmp + '0';
            }
            if (carry > 0) res[i] = carry + '0';
        }
        while (res[0]=='0' && res.size()>1) res.erase(0, 1);
        return res;
    }
};