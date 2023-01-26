class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, int>>q;
        vector<vector<pair<int, int>>>adj(n);
        for(auto  x: flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int>dist(n, INT_MAX);
        q.push({src, 0}); dist[src]=0;
        int stops=0, ans=INT_MAX;
        
        while(stops<= k and !q.empty()){
            int size=q.size();
            while(size--){
                int u= q.front().first, w=q.front().second;
                q.pop();
                for(auto x: adj[u]){
                    if(x.second + w < dist[x.first]){
                        dist[x.first]= x.second + w;
                        q.push({x.first, dist[x.first]});
                    }
                }
            }
            stops++;
        }
        return dist[dst]==INT_MAX ? -1: dist[dst]; 
    }
};