// Climbing Stairs
/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.


Example 1:

Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/


// Recursive Version, Time Limit Exceeded
class Solution {
public:
    int climbStairs(int n) {
        if (n==1 || n==2) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Top-down Dynamic Programming, time O(n), space O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> m(n+1, -1);
        return DFS(n, m);
    }
    
    int DFS(int n, vector<int>& m) {
        if (n==1 || n==2) return n;
        if (m[n] != -1) return m[n];
        return m[n] = DFS(n-1, m) + DFS(n-2, m);
    }
};

// Bottom-up Dynamic Programming, time O(n), space O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> m(n+1, 0);
        m[1] = 1, m[2] = 2;
        for (int i=3; i<=n; ++i) m[i] = m[i-1] + m[i-2];
        return m.back();
    }
};

// Space-optimized Bottom-up Dynamic Programming, time O(n), space O(1) 
class Solution {
public:
    int climbStairs(int n) {
        vector<int> m(2, 0);
        m[0] = 1, m[1] = 2;
        for (int i=3; i<=n; ++i) m[(i-1)%2] = m[(i-2)%2] + m[(i-3)%2];
        return m[(n-1)%2];
    }
};
