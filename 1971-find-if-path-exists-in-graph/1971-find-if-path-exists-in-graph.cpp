class Solution {
public:
    bool dfs(vector<vector<int>>&graph, int src, vector<bool>&vis, int dest){
        if(src== dest) return true;
        vis[src]=true;
        for(auto x: graph[src]){
            if(!vis[x]){
                if(dfs(graph,x,vis, dest)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        vector<bool>vis(n,false);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(graph,source,vis,destination);
    }
};