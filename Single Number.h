// Single Number
/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/


// Naive Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> hash;
        for (int i=0; i<n; ++i) {
            if (hash.find(A[i]) == hash.end()) hash[A[i]] = 1;
            else ++hash[A[i]];
        }
        for (int i=0; i<n; ++i) {
            if (hash[A[i]] == 1) return A[i];
        }
    }
};

// Naive Version, time complexity O(nlog(n)), space complexity O(1)
class Solution {
public:
    int singleNumber(int A[], int n) {
        sort(A, A+n);
        for (int i=0; i<n-1; i+=2) {
            if (A[i] != A[i+1]) return A[i];
        }
        return A[n-1];
    }
};

// Specific Advanced Version, time complexity O(1), space complexity O(1)
class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i=1; i<n; ++i) A[0] ^= A[i];
        return A[0];
    }
};

// General Advanced Version, time complexity O(1), space complexity O(1)
class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i=0; i<32; ++i) {
            int bit = 1<<i, count = 0;
            for (int j=0; j<n; ++j) {
                if (A[j] & bit) ++count;
            }
            if (count % 2) res |= bit;
        }
        return res;
    }
};