class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int mini=INT_MAX, finalProfit=0;
        for(int i=0; i<prices.size(); i++){
            mini=min(mini, prices[i]);
            if(prices[i] > mini+ fee){
                finalProfit+= prices[i]-mini-fee;
                mini= prices[i]-fee;
            }
        }
        return finalProfit;
    }
};