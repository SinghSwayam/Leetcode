class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minPrice) 
                minPrice = prices[i];

            int todaysPrice=prices[i] - minPrice;

            if(todaysPrice > maxProfit)
                maxProfit = todaysPrice;
        }

        return maxProfit;
    }
};