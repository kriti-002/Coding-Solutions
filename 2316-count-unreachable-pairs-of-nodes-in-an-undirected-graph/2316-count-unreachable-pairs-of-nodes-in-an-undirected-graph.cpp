class Solution {
    long long help(int i, vector<bool>&vis, vector<int>adj[]){
        long long count=1;
        vis[i]=true;
        for(auto node: adj[i]){
            if(!vis[node]){
                count+= help(node, vis, adj);
            }
        }
        return count;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long size=0, pairs=0, rem=n;
        vector<bool>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                size=help(i,vis,adj);
                pairs+= size*(rem-size);
                rem-=size;
            }
        }
        return pairs;
        
    }
};