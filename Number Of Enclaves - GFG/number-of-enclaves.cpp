//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int res=0, n=grid.size(), m=grid[0].size();
        queue<pair<int,int>>q;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    if(grid[i][j]==1){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int r= row+ delrow[i], c= col+ delcol[i];
                if(r >=0 and c>=0 and r<n and c<m and vis[r][c]==0 and grid[r][c]==1){
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 and vis[i][j]==0) res++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends