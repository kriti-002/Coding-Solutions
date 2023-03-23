class Solution {
public:
    void dfs(int src, vector<vector<int>>& adj, vector<bool>&vis){
        vis[src]=true;
        for(auto x: adj[src]){
            if(!vis[x]){
                dfs(x, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        int c=connections.size();
        if(n-1 > c) return -1;
        for(auto conn: connections){
            graph[conn[0]].push_back( conn[1] );
            graph[conn[1]].push_back( conn[0] );
        }
        int count=0;
        vector<bool>visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, graph, visited);
                count++;
            }
        }
        return count-1;
    }
};