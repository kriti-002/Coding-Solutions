class Solution {
public:
    int help(int i, int p, vector<int> g[], vector<bool>& hasApple){
        int res=0;
        for(auto x: g[i]){
            if(x!= p){
                int ans= help(x, i, g, hasApple);
                if(ans > 0 or hasApple[x]){
                    res += (ans +2);
                }
            }
        }
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool>vis(n, 0);
        vector<int>g[n];
        for(int i=0; i<edges.size(); i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        return help(0,-1,g, hasApple);
        
    }
};