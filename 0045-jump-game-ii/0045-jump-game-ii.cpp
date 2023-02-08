class Solution {
    int help(int i, int n, vector<int>&nums, vector<int>&dp){
        if(i >=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int maxi=n, check=0;
        for(int j=i+1; j<=i+nums[i]; j++){
            maxi=min(maxi, 1+ help(j, n, nums, dp));
        }
        return dp[i]=maxi;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, -1);
        return help(0,n,nums, dp);
    }
};