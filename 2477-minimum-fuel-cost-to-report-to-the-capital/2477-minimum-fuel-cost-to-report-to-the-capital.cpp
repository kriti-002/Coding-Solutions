class Solution {
    long long res=0;
    long long dfs(int src, int p, int seats, vector<bool>&vis, vector<int>adj[]){
        long long count=1;vis[src]=true;
        for(auto x: adj[src]){
            if(!vis[x] and x!=p){
               count+=dfs(x,src,seats,vis,adj);
            }  
        }
        long long cost=ceil(count/(seats*1.0));
        if(src!=0) res+=cost;
        return count;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<int>adj[n];
        for(auto x: roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n,0);
        long long cnt=dfs(0,-1,seats,vis,adj);
        return res;
        
    }
};