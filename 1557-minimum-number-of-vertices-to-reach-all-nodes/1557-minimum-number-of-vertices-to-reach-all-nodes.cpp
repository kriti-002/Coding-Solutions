class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int> in(n), res;
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        for(int i=0; i<n; i++){
            if(in[i]==0) res.push_back(i);
        }
        return res;
    }
};