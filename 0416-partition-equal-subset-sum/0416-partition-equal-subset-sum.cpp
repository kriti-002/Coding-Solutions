class Solution {
public:
    
    bool help(vector<int>&nums, vector<vector<int>>&dp, int idx, int target){
        if(target==0) return true;
        if(idx==0) return (nums[idx]==target);
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notTake=help(nums, dp, idx-1, target);
        bool take=false;
        if(nums[idx]<= target) take=help(nums, dp, idx-1, target-nums[idx]);
        return dp[idx][target]=take or notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0, n=nums.size();
        
        for(auto x: nums) sum+=x;
        if(sum&1) return false;
        int target=sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return help(nums, dp, n-1, target);
    }
};