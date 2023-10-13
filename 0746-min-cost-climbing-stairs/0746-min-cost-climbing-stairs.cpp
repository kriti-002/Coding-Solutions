class Solution {
    int help(int i, vector<int>&cost, vector<int>&dp){
        int n=cost.size();
        if(i<=1) return dp[i]=cost[i];
        if(dp[i]!=-1) return dp[i];
        
        int oneStep=help(i-1, cost, dp), twoStep=help(i-2, cost, dp);
        return dp[i]= cost[i] + min(oneStep, twoStep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int z=help(n-1, cost, dp), o= help(n-2, cost, dp);
        return min(z,o);
        
    }
};