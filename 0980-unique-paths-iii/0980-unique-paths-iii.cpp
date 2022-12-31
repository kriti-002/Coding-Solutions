class Solution {
    int ecount=1, res=0;
public:
    void help(vector<vector<int>>& grid, int x, int y, int count){
        if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size() or grid[x][y]==-1) return;
        if(grid[x][y]==2){
            if(count== ecount) res++;
            return;
        }
        
        grid[x][y]=-1; count++;
        help(grid, x+1, y, count);
        help(grid, x, y+1, count);
        help(grid, x-1, y, count);
        help(grid, x, y-1, count);
        grid[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int locX=0, locY=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1) locX=i, locY=j;
                else if(grid[i][j]==0) ecount++;
            }
        }
        help(grid,locX, locY, 0);
        return res;
        
        
    }
};