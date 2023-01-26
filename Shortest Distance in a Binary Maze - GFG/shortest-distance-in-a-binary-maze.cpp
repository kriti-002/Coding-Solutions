//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(grid[source.first][source.second]==0 or grid[destination.first][destination.second]==0) return -1;
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        
        queue<vector<int>>q;
        q.push({source.first, source.second, 0});
        vis[source.first][source.second]=1;
        
        int delRow[4]={-1,1,0,0};
        int delCol[4]={0,0,-1, 1};
        
        while(!q.empty()){
            int size= q.size();
            while(size--){
                auto x= q.front(); q.pop();
                int count= x[2];
                if(x[0]== destination.first and x[1]== destination.second) return count;
                for(int i=0; i<4; i++){
                    int row= x[0] + delRow[i];
                    int col= x[1] + delCol[i];
                    
                    if(row >=0 and row<n and col>=0 and col<m and !vis[row][col] and grid[row][col]==1){
                        q.push({row, col, count+1});
                        vis[row][col]=1;
                    }
                }
            }
            
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends