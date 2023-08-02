//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<bool>>vis(N, vector<bool>(M,0));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        
        queue<vector<int>>q;
        vis[0][0]=1;
        q.push({0,0,0});
        
        while(!q.empty()){
            auto p= q.front(); q.pop();
            int r=p[0], c=p[1], v=p[2];
            if(r==X and c==Y) return v;
            
            for(int i=0; i<4; i++){
                int row= r+ dx[i], col= c+dy[i];
                if(row>=0 and row<N and col>=0 and col<M and A[row][col]==1 and !vis[row][col]){
                    q.push({row, col, v+1});
                    vis[row][col]=1;
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends