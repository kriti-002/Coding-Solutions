class Solution {
    bool help(int i, int j,vector<vector<int>>&grid){
        int m=grid.size(), n=grid[0].size();
        if(i<0 or i>=m or j>=n or j<0) return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=1;
        bool d1= help(i, j+1, grid);
        bool d2= help(i+1, j, grid);
        bool d3= help(i-1, j, grid);
        bool d4= help(i, j-1, grid);
        return d1 and d2 and d3 and d4;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int res=0;
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j]==0){
                    res+= help(i,j,grid) ? 1: 0;
                }
            }
        }
        return res;
    }
};