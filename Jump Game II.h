// Jump Game II 
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/


// Recursive Version, Time Limit Exceeded
class Solution {
public:
    int jump(int A[], int n, int begin) {
        if (begin >= n-1) return 0;
        int minJump = INT_MAX;
        for (int i=1; i<=A[begin] && begin+i<n; ++i) {
            minJump = min(minJump, jump(A, n, begin+i));
        }
        return ++minJump;
    }
    
    int jump(int A[], int n) {
        return jump(A, n, 0);
    }
};

// Top-down Dynamic Programming Version, Time Limit Exceeded, time complexity O(n^2), space complexity O(n) 
class Solution {
public:
    int jump(int A[], int n, int begin, vector<int>& mem) {
        if (begin >= n-1) return 0;
		if (mem[begin] != -1) return mem[begin];
        int minJump = INT_MAX;
        for (int i=1; i<=A[begin] && begin+i<n; ++i) {
            minJump = min(minJump, jump(A, n, begin+i, mem));
        }
        return mem[begin] = ++minJump;
    }
    
    int jump(int A[], int n) {
		vector<int> mem(n, -1);
        return jump(A, n, 0, mem);
    }
};

// Bottom-up Dynamic Programming Version, Time Limit Exceeded, time complexity O(n^2), space complexity O(n) 
class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2) return 0;
        vector<int> mem(n, 0);
        for (int i=n-2; i>=0; --i) {
            int minJump = INT_MAX;
            for (int j=1, next=i+j; j<=A[i] && next<n; ++j) {
                 minJump = min(minJump, mem[next]+1);
            }
            mem[i] = minJump;
        }
        return mem[0];
    }
};

// Greedy Algorithm, time complexity O(n), space complexity O(1) 
class Solution {
public:
    int jump(int A[], int n) {
        int step = 0, reach = 0, i = 0;
        while (reach < n-1) {
            ++step;
            int tmpReach = 0;
            while (i <= reach) {
                tmpReach = max(tmpReach, i+A[i]);
                ++i;
            }
            reach = tmpReach;
        }
        return step;
    }
};