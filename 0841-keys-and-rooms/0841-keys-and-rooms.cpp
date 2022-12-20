class Solution {
public:
    void dfs(vector<vector<int>>&graph, int src, vector<bool>&vis){
        vis[src]=true;
        for(auto x: graph[src]){
            if(!vis[x]){
                dfs(graph, x, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n=rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};