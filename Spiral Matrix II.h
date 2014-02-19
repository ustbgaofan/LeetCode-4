// Spiral Matrix II
/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/


// Version 1 
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        for (int i=0; i<n; ++i) res[0][i] = i + 1;
        int jump = n, i = 0, j = n - 1;
        bool flag = true;
        while (--jump >= 1) {
            if (flag) {
                for (int k=0; k<jump; ++k) res[++i][j] = ++n;
                for (int k=0; k<jump; ++k) res[i][--j] = ++n;
            } else {
                for (int k=0; k<jump; ++k) res[--i][j] = ++n;
                for (int k=0; k<jump; ++k) res[i][++j] = ++n;
            } 
            flag = flag ? false: true;
        }
        return res;
    }
};

// Version 2
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int i = 0, val = 0;
        for (--n; n>i; --n, ++i) {
            for (int j=i; j<n; ++j) res[i][j] = ++val;
            for (int j=i; j<n; ++j) res[j][n] = ++val;
            for (int j=n; j>i; --j) res[n][j] = ++val;
            for (int j=n; j>i; --j) res[j][i] = ++val;
        }
        if (n == i) res[i][i] = ++val;
        return res;
    }
};