//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int src, vector<bool>&vis, vector<int>g[]){
        vis[src]=true;
        for(auto x: g[src]){
            if(!vis[x]) dfs(x, vis, g);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>g[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        vector<bool>vis(V, 0);
        int count=0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, g);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends