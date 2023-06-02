class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    long long x1=bombs[i][0],x2=bombs[j][0], y1=bombs[i][1], y2= bombs[j][1], r1= bombs[i][2];
                    if((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) <= r1*r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int res=INT_MIN;
        for(int i=0; i<n; i++){
            int count=0;
            vector<bool>vis(n,0);
            dfs(i, count, adj, vis);
            res=max(res, count);
        }
        return res;
    }
    private:
    void dfs(int i, int &c, vector<int>adj[], vector<bool>&vis){
        vis[i]=1;
        c++;
        for(auto node: adj[i]){
            if(!vis[node]) dfs(node, c, adj, vis);
        }
    }
};