class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res=0, n=grid.size();
        queue<pair<int, int>>q;
        vector<vector<bool>>vis(n, vector<bool>(n,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                } 
            }
        }
        if(q.size()== n*n) return -1;
        
        while(!q.empty()){
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            int size= q.size();
            res++;
            while(size--){
                auto x=q.front(); q.pop();
                for(int i=0; i<4; i++){
                    int row=x.first+ delRow[i];
                    int col= x.second+ delCol[i];
                    if(row>=0 and row<n and col>=0 and col<n and grid[row][col]==0 and !vis[row][col]){
                        q.push({row,col});
                        vis[row][col]=1;
                    }
                }
            }
            
        }
        return res>0 ? res-1: -1;
    }
};