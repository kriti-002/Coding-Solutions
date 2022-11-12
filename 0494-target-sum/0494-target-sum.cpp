class Solution {
public:
    int help(vector<int>&arr, vector<vector<int>>&dp, int idx, int target){
    if(idx==0){
        if(target==0 and arr[idx]==0) return 2; //pick as well as not pick
        if(target==0 or arr[idx]==target) return 1;
        return 0;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    
    int pick=0;
    int notPick= help(arr,dp, idx-1, target);
    if(arr[idx]<= target) pick= help(arr, dp, idx-1, target-arr[idx]);
    return dp[idx][target]=(pick+ notPick);
}
    
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum=0;
    for(auto &x: arr) sum+=x;
    if((sum-d)<0 or (sum-d)&1) return false;
    int target=(sum-d)/2;
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    return help(arr, dp, n-1, target);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};