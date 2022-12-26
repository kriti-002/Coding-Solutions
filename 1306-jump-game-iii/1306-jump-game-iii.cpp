class Solution {
public:
    bool help(vector<int>&arr, vector<bool>&dp, int start){
        if(start < 0 or start >= arr.size() or dp[start]) return false;
        if(arr[start]==0) return true;
        dp[start]=true;
        
        bool left= help(arr, dp, start+ arr[start]);
        bool right= help(arr, dp, start-arr[start]);
        return dp[start]= left or right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> dp(arr.size(), 0);
        return help(arr,dp, start);
    }
};