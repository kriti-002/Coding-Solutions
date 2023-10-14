class Solution {
    int help(int i, int wall, vector<int>&cost, vector<int>&time, vector<vector<int>>&dp){
        int n=cost.size();
        if(wall<=0) return 0;
        if(i<0) return 1e9;
        if(dp[i][wall]!=-1) return dp[i][wall];
        
        int paid= cost[i] + help(i-1, wall-1-time[i], cost, time, dp), unpaid= help(i-1, wall, cost, time, dp);
        return dp[i][wall]= min(paid, unpaid);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return help(n-1,n, cost, time, dp);
    }
};