// Add Binary 
/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

// time O(max(m,n)), space O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int M = a.size(), N = b.size();
        string res(max(M, N)+1, '0');
        int carry = 0;
        for (int i=M-1, j=N-1, k=res.size()-1; i>=0 || j>=0; --i, --j, --k) {
            int tmp = carry;
            if (i >= 0) tmp += a[i] - '0';
            if (j >= 0) tmp += b[j] - '0';
            carry = tmp / 2;
            res[k] = tmp % 2 + '0';
        }
        if (carry > 0) res[0] = '1';
        while (res[0]=='0' && res.size()>1) res.erase(0, 1);
        return res;
    }
};
