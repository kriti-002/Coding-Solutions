class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, n);
        dp[0]=0;
        
        int maxi=n;
        for(int i=0; i<n-1; i++){
          for(int j=i+1; j<=i+nums[i] and j<n; j++){
            dp[j]=min(dp[j], 1+ dp[i]);
  }
        }
        return dp[n-1];
        
    }
};