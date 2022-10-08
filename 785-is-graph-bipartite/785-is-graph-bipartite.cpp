class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(!bfs(graph, color, i)) return false;
            }
        }
        return true;  
    }
    bool bfs(vector<vector<int>>&graph, vector<int>&color, int src){
        color[src]=1;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            auto x= q.front(); q.pop();
            for(auto y: graph[x]){
                if(color[y]==-1){
                    color[y]=1-color[x];
                    q.push(y);
                }else if(color[x]==color[y]) return false;
            }
        }
        return true;
    }
};