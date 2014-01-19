// Climbing Stairs
/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/


// Recursive Version, Time Limit Exceeded
class Solution {
public:
    int climbStairs(int n) {
        if (n==1 || n==2) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Top-down Dynamic Programming Version 
class Solution {
public:
    int climbStairs(int n) {
        int *mem = new int[n];
        memset(mem, 0, sizeof(int)*n);
        int res = climbStairs(n, mem);
        delete[] mem;
        return res;
    }
    
    int climbStairs(int n, int* mem) {
        if (mem[n-1]) return mem[n-1];
        if (n==1 || n==2) mem[n-1] = n;
        else mem[n-1] = climbStairs(n-1, mem) + climbStairs(n-2, mem);
        return mem[n-1];
    }
};

// Bottom-up Dynamic Programming Version  
class Solution {
public:
    int climbStairs(int n) {
        int *mem = new int[n];
        memset(mem, 0, sizeof(int)*n);
        mem[0] = 1, mem[1] = 2;
        for (int i=2; i<n; ++i) 
            mem[i] = mem[i-1] + mem[i-2];
        int res = mem[n-1];
        delete[] mem;
        return res;
    }
};

// Space Optimized Bottom-up Dynamic Programming Version 
class Solution {
public:
    int climbStairs(int n) {
        int mem[2] = {1, 2};
        for (int i=2; i<n; ++i) 
            mem[i%2] = mem[0] + mem[1];
        return mem[(n-1)%2];
    }
};