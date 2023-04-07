class Solution {
    void help(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        int m=grid.size(), n=grid[0].size();
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]==0 or vis[i][j]) return;
        vis[i][j]=1;
        
        help(i, j-1, grid, vis);
        help(i+1, j, grid, vis);
        help(i, j+1, grid, vis);
        help(i-1, j, grid, vis);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n,0));
        
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 and !vis[i][0]) help(i,0,grid, vis);
            if(grid[i][n-1]==1 and !vis[i][n-1]) help(i, n-1, grid, vis);
            
        }
        for(int i=0; i<n; i++){
            if(grid[0][i]==1 and !vis[0][i]) help(0,i,grid, vis);
            if(grid[m-1][i]==1 and !vis[m-1][i]) help(m-1, i, grid, vis);
        }
        int res=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 and !vis[i][j]) res++;
            }
        }
        return res;
    }
};