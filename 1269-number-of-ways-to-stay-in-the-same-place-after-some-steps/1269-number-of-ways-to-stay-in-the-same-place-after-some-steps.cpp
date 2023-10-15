class Solution {
    int mod=1e9+7;
    int help(int i, int steps, int arrLen, vector<vector<int>>&dp){
        if(steps==0){
            if(i==0) return 1;
            return 0;
        }
        if(i>= arrLen) return 0;
        if(dp[i][steps]!=-1) return dp[i][steps];
        
        int res= help(i, steps-1, arrLen, dp)%mod;
        if(i> 0) res= (res+ help(i-1, steps-1, arrLen, dp))%mod;
        
        if(i<arrLen-1) res= (res+ help(i+1, steps-1, arrLen, dp))%mod;
        
        
        return dp[i][steps]= res;
    }
public:
    int numWays(int steps, int arrLen) {
        arrLen=min(steps, arrLen);
        vector<vector<int>>dp(arrLen, vector<int>(steps+1, -1));
        return help(0, steps, arrLen, dp);
    }
};