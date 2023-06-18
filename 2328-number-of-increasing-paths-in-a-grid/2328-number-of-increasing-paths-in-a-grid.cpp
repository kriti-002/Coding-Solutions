class Solution {
    int mod=1e9+7;
    int help(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        int m=grid.size(), n=grid[0].size();
        if(i<0 or i>=m or j<0 or j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res=0, left=0, right=0, top=0, bottom=0;
        if(i+1< m and grid[i+1][j]> grid[i][j]) right=help(i+1,j, grid, dp)%mod;
        if(i-1>=0 and grid[i-1][j] > grid[i][j]) left=help(i-1, j, grid, dp)%mod;
        if(j+1<n and grid[i][j+1] > grid[i][j]) bottom=help(i,j+1, grid, dp)%mod;
        if(j-1>=0 and grid[i][j-1]> grid[i][j]) top=help(i, j-1, grid, dp)%mod;
        return dp[i][j] = ((((right+left)%mod+bottom)%mod+top)%mod+1)%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;
        vector<vector<int>>dp(m, vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]<0) help(i,j,grid,dp);
                res= (res+dp[i][j])%mod;
            }
        }
        return res;
    }
};