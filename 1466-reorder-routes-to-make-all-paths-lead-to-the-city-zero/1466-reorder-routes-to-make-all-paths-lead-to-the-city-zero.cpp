class Solution {
    void help(int i,int &count, vector<int>adj[], vector<bool>&vis){
        vis[i]=true;
        for(auto node: adj[i]){
            if(!vis[abs(node)]){
                if(node >0) count++;
                help(abs(node),count, adj,vis);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        int count=0;
        vector<bool>vis(n,0);
        help(0,count, adj, vis);
        return count;
    }
};