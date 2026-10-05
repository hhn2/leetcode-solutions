// Last updated: 10/4/2026, 10:54:10 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar = INT_MAX;
        int price = 0;
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] <minsofar){
                minsofar = prices[i];
            }
            if(prices[i]-minsofar > price){
                price = prices[i] - minsofar;
            }
        }
        return price;
    }
};