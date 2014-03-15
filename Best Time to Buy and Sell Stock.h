// Time Limit Exceeded Version
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0;
        int size = prices.size();
        for (int i=0; i<size; ++i)
            for (int j=i+1; j<size; ++j) 
                maxProfit = max(maxProfit, prices[j]-prices[i]);
        return maxProfit;
    }
};

// Backward-forward Version, store max sales
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
		if (size == 0) return 0;
        vector<int> maxSales(size, 0);
        maxSales[size-1] = prices[size-1];
        for (int i=size-2; i>=0; --i)
			maxSales[i] = max(prices[i], maxSales[i+1]);
        int maxProfit = 0;
        for (int i=0; i<size-1; ++i)
            maxProfit = max(maxProfit, maxSales[i+1]-prices[i]);
        return maxProfit;
    }
};

// Forward-backward Version, store min buys
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
		if (size == 0) return 0;
        vector<int> minBuys(size, 0);
        minBuys[0] = prices[0];
        for (int i=1; i<size; ++i)
            minBuys[i] = min(prices[i], minBuys[i-1]);
        int maxProfit = 0;
        for (int i=size-1; i>=1; --i)
            maxProfit = max(maxProfit, prices[i]-minBuys[i-1]);
        return maxProfit;
    }
};

// Backward-forward Version with Constant Space
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (size == 0) return 0;
        int maxProfit = 0, maxSale = prices[size-1];
        for (int i=size-2; i>=0; --i) {
            maxSale = max(maxSale, prices[i]);
            maxProfit = max(maxProfit, maxSale-prices[i]);
        }
        return maxProfit;
    }
};

// Forward-backward Version with Constant Space
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (size == 0) return 0;
        int maxProfit = 0, minBuy = prices[0];
        for (int i=1; i<size; ++i) {
            minBuy = min(minBuy, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minBuy);
        }
        return maxProfit;
    }
};