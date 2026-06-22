class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy=prices[0];
        int profit=0;

        for (int i=1;i<prices.size();i++){
            if (prices[i]>bestBuy){
                profit=max(profit,prices[i]-bestBuy);
            }

            bestBuy=min(bestBuy,prices[i]);
        }

        return profit;
    }
};