class Solution {
    // state 1: i, j+1 --- usi pile se hatao
    //state 2: i+1, j ---- agle pile se hatao
    int help(vector<vector<int>>& piles, vector<vector<int>>&dp, int i, int coins){
        if(i==0) return 0;
        if(dp[i][coins]!=-1) return dp[i][coins];
        int sum=0;
        for(int j=0; j<=min((int)piles[i-1].size(), coins); j++){
            if(j>0) sum+=piles[i-1][j-1];
            dp[i][coins]= max(dp[i][coins], help(piles, dp,i-1, coins-j)+sum);
        }
        return dp[i][coins];
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        return help(piles, dp, n, k);
        
    }
};