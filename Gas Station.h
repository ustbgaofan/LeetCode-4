// Gas Station
/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/


// Naive Version, Time Limit Exceeded, time complexity O(n^2), space complexity O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        for (int i=0; i<N; ++i) {
            int j = 0, tank = 0;
            for (; j<N; ++j) {
                tank += gas[(i+j)%N];
                tank -= cost[(i+j)%N];
                if (tank < 0) break;
            }
            if (j == N) return i;
        }
        return -1;
    }
};

// Advanced Version, time complexity O(n), space complexity O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        for (int i=0; i<N; ++i) {
            int j = 0, tank = 0;
            for (; j<N; ++j) {
                tank += gas[(i+j)%N];
                tank -= cost[(i+j)%N];
                if (tank < 0) break;
            }
            if (j == N) return i;
            if (i+j+1 >= N) return -1;
            i += j;
        }
        return -1;
    }
};

// Advanced Version, time complexity O(n), space complexity O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, total = 0, res = -1;
        for (int i=0; i<gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                res = i;
            }
        }
        return (total < 0)? -1: res+1;
    }
};