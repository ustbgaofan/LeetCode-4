/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

// Brute force, time O(n^2), space O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i=0; i<prices.size(); ++i)
            for (int j=i+1; j<prices.size(); ++j) 
                res = max(res, prices[j]-prices[i]);
        return res;
    }
};

// time O(n), space O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int res = 0, cost = prices[0];
        for (int i=1; i<prices.size(); ++i) {
            res = max(res, prices[i]-cost);
            cost = min(cost, prices[i]);
        }
        return res;
    }
};
