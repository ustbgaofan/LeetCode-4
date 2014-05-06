// Permutation Sequence
/*
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/


// Naive Version based on Next Permutation, Time Limit Exceeded, time complexity O(kn) (k<=n!), space complexity O(1)
class Solution {
public:
    void nextPermutation(string &num) {
        int N = num.size(), i = N - 1;
        for (; i>=1 && num[i]<=num[i-1]; --i);
        if (i == 0) {
            reverse(num.begin(), num.end());
            return;
        }
        int j = i;
        for (; j<N && num[i-1]<num[j]; ++j);
        swap(num[j-1], num[i-1]);
        reverse(num.begin()+i, num.end());
    }
    
    string getPermutation(int n, int k) {
        string res(n, '0');
        for (int i=0; i<n; ++i) res[i] += i + 1;
        for (int i=1; i<k; ++i) nextPermutation(res);
        return res;
    }
};

// Advanced Version, time complexity O(n^2), space complexity O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        string num(n, '0'), res(n, '0');
        int P = 1;
        for (int i=1; i<=n; ++i) {
            num[i-1] += i;
            P *= i;
        }
        for (int i=0; i<n; ++i) {
            P /= (n-i);
            int j = k;
            j = (j-1) / P;
            res[i] = num[j];
            num.erase(j, 1);
            k -= j * P;
        }
        return res;
    }
};