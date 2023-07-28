class Solution {
public:
    int help(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int scoreLeft= nums[i]- help(i+1, j, nums, dp), scoreRight= nums[j]-help(i, j-1, nums, dp);
        return dp[i][j]= max(scoreLeft, scoreRight);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return help(0, n-1, nums, dp)>=0;
    }
};