class Solution {
public:
    int help(int i, int p,vector<int>& nums, vector<vector<int>>&dp){
        if(i==nums.size()) return 0;
        
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        int len= help(i+1, p, nums, dp);
        if(p== -1 or nums[p] < nums[i]) 
            len=max(len,1+ help(i+1,i,nums,dp));
        
        return dp[i][p+1]= len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return help(0,-1,nums,dp);
    }
};