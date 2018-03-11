// Gray Code
/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

// time O(n2^n), space O(1)
// n=1: 0, 1
// n=2: 00, 01 | 11, 10
// n=3: 000, 001, 011, 010 | 110, 111, 101, 100
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for (int i=0; i<n; ++i) {
            int N = res.size();
            for (int j=N-1; j>=0; --j) {
                res.push_back(res[j] | 1<<i);
            }
        }
        return res;
    }
};
