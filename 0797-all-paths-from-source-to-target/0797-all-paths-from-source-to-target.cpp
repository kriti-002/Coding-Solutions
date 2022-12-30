class Solution {
public:
    vector<vector<int>> res;
    void dfs(int src, vector<vector<int>>&graph, vector<int>&vis){
        vis.push_back(src);
        
        if(src== graph.size()-1){
            res.push_back(vis);
        }else{
            for(auto x: graph[src]){
                dfs(x, graph, vis);
            }
        }
        vis.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> vis;
        dfs(0, graph, vis);
        return res;
    }
};