class Solution {
public:
    int help(vector<int>& coins, vector<vector<int>>& dp, int idx, int amount){
      if(idx==0){
        if(amount % coins[idx]==0) return 1;
        else return 0;  
    }
      if(dp[idx][amount]!=-1) return dp[idx][amount];
      int pick=0, notPick= help(coins, dp, idx-1, amount);
      if(coins[idx]<= amount) pick= help(coins, dp, idx, amount-coins[idx]);
      return dp[idx][amount]= pick+ notPick;  
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        return help(coins, dp, coins.size()-1, amount);
    }
};