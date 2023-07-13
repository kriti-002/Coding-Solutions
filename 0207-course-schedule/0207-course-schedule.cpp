class Solution {
public:
    bool dfs(int i,vector<int>adj[],vector<bool>&vis,vector<bool>&tmp){
        vis[i]=true; tmp[i]=true;
        for(auto x: adj[i]){
            if(!vis[x]){  
                if(dfs(x,adj,vis,tmp)) return true;
            }else if(tmp[x]){
                return true;
            }
        }
        tmp[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<bool>vis(numCourses,0);
      vector<bool>tmp(numCourses,0);
      int size=prerequisites.size();
      vector<int>adj[numCourses];
        
      for(int i=0; i<size; i++){
          adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }
        
      for(int i=0; i<numCourses; i++){
          if(!vis[i]){
              if(dfs(i,adj,vis,tmp)) return false;
          }
      }
      return true;
    }
};