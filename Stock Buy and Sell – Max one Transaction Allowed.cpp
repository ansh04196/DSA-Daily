class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();

        if (n < 2) return 0;
    
        int minPrice = INT_MAX; 
        int maxProfit = 0;      
        for (int i = 0; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
    
        return maxProfit;
    }
};
