class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir={-1,0,1,0,-1};
        queue<pair<int, int>>q; 
        int freshOranges= 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({i,j});   
                }
                if(grid[i][j]==1) freshOranges++;
            }
        }
        int res=-1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto x= q.front(); q.pop();
                for(int i=0; i<4; i++){
                    int r=x.first+dir[i];
                    int c=x.second+dir[i+1];
                    if(r>=0 and r<grid.size() and c>=0 and c<grid[0].size() and grid[r][c]==1){
                        grid[r][c]=2;
                        q.push({r,c});
                        freshOranges--;
                    }
            }
        }
            res++;
        }
        if(freshOranges >0) return -1;
        if(res==-1) return 0;
        return res;
    }
};