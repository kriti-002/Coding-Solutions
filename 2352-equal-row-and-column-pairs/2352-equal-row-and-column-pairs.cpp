class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       vector<vector<int>> t=grid;
       int n= grid.size();
       for(int i=0; i<n; i++){
           for(int j=i+1; j<n; j++){
               swap(grid[i][j], grid[j][i]);
           }
       }
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(t[i]== grid[j]) res++;
            }
        }
        return res;
    }
};