class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int profit1 = INT_MIN;
        int profit2 = INT_MIN;
        
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < min1)
            {
                min1 = prices[i];
            }
            int curr1 = prices[i] - min1;
            
            if(curr1 > profit1)
            {
                profit1 = curr1;
            }
            min2 = min(min2, prices[i] - profit1);
            int curr2 = prices[i] - min2;
            if(curr2 > profit2)
            {
                profit2 = curr2;
            }
        }
        return profit2;
    }
};
