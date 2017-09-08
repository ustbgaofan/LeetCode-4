// Add Binary 
/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/


// minLen Version
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size(), minLen = min(aLen, bLen), carryBit = 0;
        string res;
        for (int i=1; i<=minLen; ++i) {
            int tmp = a[aLen-i]-'0' + b[bLen-i]-'0' + carryBit;
            res += tmp%2 + '0';
            carryBit = tmp / 2;
        }
        for (int i=aLen-1-res.size(); i>=0; --i) {
            int tmp = a[i]-'0' + carryBit;
            res += tmp%2 + '0';
            carryBit = tmp / 2;
        }
        for (int i=bLen-1-res.size(); i>=0; --i) {
            int tmp = b[i]-'0' + carryBit;
            res += tmp%2 + '0';
            carryBit = tmp / 2;
        }
        if (carryBit) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};

// maxLen Version
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size(), maxLen = max(aLen, bLen), carryBit = 0;
        string res;
        for (int i=1; i<=maxLen; ++i) {
            int tmp = carryBit;
            if (i <= aLen) tmp += a[aLen-i] - '0'; 
            if (i <= bLen) tmp += b[bLen-i] - '0'; 
            res += tmp%2 + '0';
            carryBit = tmp / 2;
        }
        if (carryBit) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        int M = a.size(), N = b.size();
        string res(max(M, N)+1, '0');
        int carry = 0;
        for (int i=M-1, j=N-1, k=max(M,N); i>=0 || j>=0; --i, --j, --k) {
            int tmp = carry;
            if (i>=0) tmp += a[i] - '0';
            if (j>=0) tmp += b[j] - '0';
            carry = tmp / 2;
            res[k] = tmp % 2 + '0';
        }
        if (carry > 0) res[0] = '1';
        while (res[0]=='0' && res.size()>1) res.erase(0, 1);
        return res;
    }
};
