class Solution {
    map<int,int>mp;
    bool help(int i, int p, vector<int>&stones, vector<vector<int>>&dp){
        if(i == stones.size()-1) return dp[i][p] = 1;
        if(dp[i][p] != -1) return dp[i][p];
        
        for(int t=p-1; t<=p+1; t++){
            if(t > 0 && mp.find(stones[i]+t) != mp.end()){
                int ind = mp[stones[i]+t];
                if(help(ind, t,stones, dp)) return dp[i][p] = 1;
            }
        }
        return dp[i][p] = 0;
    }
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        for(int i=0; i<n; i++) mp[stones[i]]=i;
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return help(0,0,stones, dp);
    }
};