
class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&m, vector<int>&informTime, int headID){
        int res=0;
        for(auto x: m[headID]){
            res=max(res, dfs(m,informTime, x));
        }
        return informTime[headID]+res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int ,vector<int>>m;
        for(int i=0; i<n; i++){
            if(manager[i]!=-1){
                m[manager[i]].push_back(i);     
            }
        }
        return dfs(m, informTime, headID);
        
    }
};