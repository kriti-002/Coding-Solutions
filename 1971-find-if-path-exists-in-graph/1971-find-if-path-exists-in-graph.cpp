class Solution {
    void dfs(int s, vector<int>adj[], vector<bool>&vis){
        if(vis[s]) return;
        
        vis[s]=true;
        for(auto x: adj[s]){
            if(!vis[x]) dfs(x,adj,vis);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n, false);
        vector<int>adj[n];
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(source, adj, vis);
        return vis[destination];
    }
};