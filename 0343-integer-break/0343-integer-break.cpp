class Solution {
    int help(int i, vector<int>&dp){
        if(i<=3) return i;
        if(dp[i]!=0) return dp[i];
        
        int res=i;
        for(int j=2; j<i; j++){
            res=max(res, j* help(i-j, dp));
        }
        return dp[i]=res;
        
        
    }
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        vector<int>dp(n+1, 0);
        return help(n, dp);
    }
};