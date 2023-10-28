class Solution {
public:
    long long ans = 0ll;
    int mod = 1e9+7;
    int help(int u,int n,vector<int> adj[],vector<vector<int>> &dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[u][n]!=-1) return dp[u][n];
        long long sum = 0ll;
        for(auto i:adj[u]){
            sum = ((sum % mod) + (help(i,n-1,adj,dp)%mod))%mod;
        }
        return dp[u][n] = sum;
    }
    int countVowelPermutation(int n) {
        vector<int> adj[5];
        adj[0] = {1};
        adj[1] = {0,2};
        adj[2] = {0,1,3,4};
        adj[3] = {2,4};
        adj[4] = {0};
        vector<vector<int>> dp(5,vector<int> (n+1,-1));
        for(int i=0;i<5;i++){
            ans = ((ans % mod) + (help(i,n-1,adj,dp)%mod))%mod;
        }
        return ans;
    }
};