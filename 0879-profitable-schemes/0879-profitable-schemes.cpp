class Solution {
    int mod= 1e9+7;
    int help(int i,int count, int p,int n, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>&dp){
        if(i==group.size()) return p>= minProfit;
        if(dp[i][count][p]!=-1) return dp[i][count][p];
        
        int totWays = help(i + 1, count, p, n, minProfit, group, profit,dp);
        if (count + group[i] <= n) {
            totWays += help(i + 1, count + group[i], min(minProfit, p + profit[i]), n, minProfit, group, profit,dp);
        }
        
        return dp[i][count][p] = totWays % mod;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>>dp(101, vector<vector<int>>(101,vector<int>(101,-1)));
        return help(0,0,0,n,minProfit,group, profit, dp);
    }
};