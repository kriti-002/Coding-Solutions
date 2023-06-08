class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size()-1, n=grid[0].size();
          int count=0, i=0;
          while(i<n and m>=0){
              if(grid[m][i]<0) {
                  count+=n-i;
                  m--;
              }
              else i++;
          }      
          return count;
    }
};