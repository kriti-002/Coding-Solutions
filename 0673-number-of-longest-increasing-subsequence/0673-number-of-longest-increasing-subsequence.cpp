class Solution {
    /*vector<vector<int>>dp;
    int help(int i, int p,vector<int>& nums, vector<vector<int>>&dp){
        if(i==nums.size()) return 0;
        
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        int len= help(i+1, p, nums, dp);
        if(p== -1 or nums[p] < nums[i]) 
            len=max(len,1+ help(i+1,i,nums,dp));
        
        return dp[i][p+1]= len;
    }
    int length(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1, vector<int>(n+1,-1));
        return help(0,-1,nums,dp);
    }
    int l= length(nums), res=0;
        for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[0].size(); j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return res;*/
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        const int n = nums.size();
        vector<int> lis(n,1);  
        vector<int> count(n,1); 
        int maxLen = 1; 
		
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(lis[j] + 1 > lis[i]){ 
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    } 
					else if(lis[j]+1 == lis[i]){ 
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen,lis[i]);
        }
        
        int numOfLIS = 0;
        for(int i=0;i<n;i++){
            if(lis[i]==maxLen)
                numOfLIS += count[i];
        }
            
        return numOfLIS;
    }
};