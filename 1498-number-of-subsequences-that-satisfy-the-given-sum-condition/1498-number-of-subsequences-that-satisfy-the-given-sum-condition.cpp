class Solution {
public:
    int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n= nums.size(), i=0, j=n-1, res=0;
        sort(nums.begin(), nums.end());
        vector<int>dp(n+1,1);
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%mod;
        }
        while(i<=j){
            if(nums[j]+nums[i]<=target){
                res=(res+ dp[j-i])%mod;
                i++;
            }else j--;
        }
        return res;
    }
};