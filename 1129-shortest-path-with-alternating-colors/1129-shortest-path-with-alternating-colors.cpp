class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>res(n,-1);
        vector<vector<bool>>vis(n, vector<bool>(2,0));
        
        vector<pair<int,int>>adj[n];
        for(auto x: redEdges){
            adj[x[0]].push_back({x[1], 0});
        }
        for(auto x: blueEdges){
            adj[x[0]].push_back({x[1],1});
        }
        queue<vector<int>>q;
        q.push({0,0,-1});
        vis[0][0]=1; vis[0][1]=1;
        res[0]=0;
        
        while(!q.empty()){
            auto x=q.front(); q.pop();
            int node= x[0], steps=x[1], prevCol=x[2];
            for(auto y: adj[node]){
                int neighbour=y.first, color=y.second;
                if(!vis[neighbour][color] and prevCol!= color){
                    q.push({neighbour, steps+1, color});
                    vis[neighbour][color]=1;
                    if(res[neighbour]==-1) res[neighbour]=steps+1;
                }
            }
        }
        return res;
        
    }
};