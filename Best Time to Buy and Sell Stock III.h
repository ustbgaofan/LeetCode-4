// Best Time to Buy and Sell Stock III
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


// Naive Version, time complexity O(n^2), space complexity O(1) 
class Solution {
public:
    int maxProfit(const vector<int> &prices, int begin, int end) {
        int res = 0, maxSale = prices[end];
        for (int i=end-1; i>=begin; --i) {
            maxSale = max(maxSale, prices[i]);
            res = max(res, maxSale-prices[i]);
        }
        return res;
    }
    
    int maxProfit(vector<int> &prices) {
        int res = 0, N = prices.size();
        for (int i=0; i<N; ++i) {
            int curProfit = maxProfit(prices, 0, i) + maxProfit(prices, i, N-1);
            res = max(res, curProfit);
        }
        return res;
    }
};

// Dynamic Programming Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N < 2) return 0;
        vector<int> l(N, 0);
        for (int i=1, minBuy=prices[0]; i<N; ++i) {
            minBuy = min(minBuy, prices[i]);
            l[i] = max(l[i-1], prices[i]-minBuy);
        }
        vector<int> r(N, 0);
        for (int i=N-2, maxSale=prices[N-1]; i>=0; --i) {
            maxSale = max(maxSale, prices[i]);
            r[i] = max(r[i+1], maxSale-prices[i]);
        }
        int res = 0;
        for (int i=0; i<N; ++i) res = max(res, l[i]+r[i]);
        return res;
    }
};