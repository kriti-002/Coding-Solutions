class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>vp;
        int m= matrix.size(), n=matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0) vp.push_back({i,j});
            }
        }
        for(int i=0; i<vp.size(); i++){
            int j=vp[i].first, k= vp[i].second;
            int c1=0, c2=0;
            while(c1<m){
                matrix[c1][k]=0;
                c1++;
            }
            while(c2<n){
                matrix[j][c2]=0;
                c2++;
            }
        }
    }
};