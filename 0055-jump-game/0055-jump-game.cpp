class Solution {
public:
    bool help(vector<int>&nums, int idx, vector<int>&dp){
        if(idx== nums.size()-1) return true;
        if(nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx];
        
        int jump= idx+ nums[idx];
        for(int j=idx+1; j<= jump; j++){
            if(help(nums, j, dp) and j< nums.size()) return dp[idx]=true;
            
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return help(nums, 0, dp);
    }
};