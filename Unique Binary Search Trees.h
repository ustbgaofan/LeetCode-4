// Unique Binary Search Trees
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

// Recursive Version, passed!
class Solution {
public:
    int numTrees(int begin, int end) {
        if (begin >= end) return 1;
        int count = 0;
        for (int i=begin; i<=end; ++i) {
            count += numTrees(begin, i-1) * numTrees(i+1, end);
		}
        return count;
    }
    
    int numTrees(int n) {
        return numTrees(1, n);
    }
};

// Top-down Dynamic Programming Version
class Solution {
public:
    int numTrees(int begin, int end, vector<int> &mem) {
        if (begin >= end) return 1;
        if (mem[end-begin]) return mem[end-begin];
        int count = 0;
        for (int i=begin; i<=end; ++i) {
            count += numTrees(begin, i-1, mem) * numTrees(i+1, end, mem);
        }
        mem[end-begin] = count;
        return count;
    }
    
    int numTrees(int n) {
        vector<int> mem(n, 0);
        return numTrees(1, n, mem);
    }
};

// Bottom-up Dynamic Programming Version
class Solution {
public:
    int numTrees(int n) {
        vector<int> mem(n+1, 0);
        mem[0] = mem[1] = 1;
        for (int i=2; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                mem[i] += mem[j] * mem[i-1-j];
            }
        }
        return mem.back();
    }
};