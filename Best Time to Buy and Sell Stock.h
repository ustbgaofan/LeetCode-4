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

// time O(n), space O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, minB = INT_MAX;
        for (int i=0; i<prices.size(); ++i) {
            minB = min(minB, prices[i]);
            maxP = max(maxP, prices[i] - minB);
        }
        return maxP;
    }
};
