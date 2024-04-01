class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size(), n=matrix[0].size();
        vector<pair<int,int>>vp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!matrix[i][j])vp.push_back({i,j});
            }
        }
        for(int i=0; i<vp.size(); i++){
            int row=vp[i].first, col=vp[i].second;
            int x=0,y=0;
            while(x< m){
                matrix[x][col]=0;
                x++;
            }
            while(y < n){
                matrix[row][y]=0;
                y++;
            }
        }
    }
};