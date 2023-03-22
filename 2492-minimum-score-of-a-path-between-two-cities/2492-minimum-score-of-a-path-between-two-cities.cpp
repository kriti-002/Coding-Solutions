class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>>adj[n+1];
        for(auto road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector<bool>vis(n+1,0);
        queue<int>q;
        int res= INT_MAX;
        q.push(1);
        while(!q.empty()){
            auto node= q.front(); q.pop();
            for(auto neigh: adj[node]){
                res=min(res, neigh.second);
                if(!vis[neigh.first]){
                    q.push(neigh.first);
                    vis[neigh.first]=1;
                }
            }
        }
        return res;
        
    }
};