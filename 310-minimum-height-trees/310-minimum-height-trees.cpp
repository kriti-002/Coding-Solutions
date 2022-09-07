class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int>ind(n,0);
        vector<int> res;
        vector<int>graph[n];
        
        if(n==1) res.push_back(0);
        
        for(auto &e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            ind[e[0]]++;
            ind[e[1]]++;
        }
        
        queue<int>q;
        for(int i=0; i<n; i++){
            if(ind[i]==1) q.push(i);
        }
        
        while(!q.empty()){
            int s=q.size(); res.clear();
            for(int i=0; i<s; i++){
                int x= q.front(); q.pop();
                res.push_back(x);
                for(auto child: graph[x]){
                    ind[child]--;
                    if(ind[child]==1) q.push(child);
                }
            }  
        }
       
        return res;
    }
};