class Solution {
public:
    bool help(int x, int y, int n, vector<vector<int>>& grid, vector<vector<bool>>&vis){
        return (x>=0 and x<n and y>=0 and y<n and grid[x][y]==0 and !vis[x][y]);
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid[0].size(), size=0; 
        vector<vector<bool>> vis(n, vector<bool>(n,0));
        int res= 0;
        queue<pair<int, int>>q;
        if(grid[0][0]==0){
            q.push({0,0});
            vis[0][0]=true;
        }
        while(!q.empty()){
            size=q.size();
            res++;
            for(int i=0; i<size; i++){
                auto x=q.front();
                q.pop();
                int j=x.first, k=x.second;
                if(j==n-1 and k==n-1) return res;
                for(int a = j - 1; a <= j + 1 ; a++){
                    for(int b = k - 1; b <= k + 1; b++){
                        if(help(a,b,n,grid,vis)){
                            q.push({a,b});
                            vis[a][b]=true;
                        }
                    }
                }
            }
            
            
        }
        
        return -1;
    }
};