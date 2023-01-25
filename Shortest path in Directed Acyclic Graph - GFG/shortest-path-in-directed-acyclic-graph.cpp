//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>res(N, INT_MAX);
        queue<int>q;
        
        vector<pair<int, int>>adj[N];
        for(auto x: edges){
            adj[x[0]].push_back({x[1], x[2]});
        }
        int src=0; q.push(src); res[src]=0;
        
        while(!q.empty()){
            auto x= q.front(); q.pop();
            for(auto y: adj[x]){
                int u=y.first,v=y.second;
                if(res[x] + v < res[u]){
                    res[u]= res[x]+v;
                    q.push(u);
                }
            }
        }
        for(int i=0; i<N; i++){
            if(res[i]== INT_MAX) res[i]=-1;
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
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends