class Solution {
    
public:
    int longestCycle(vector<int>& edges) {
            int n = edges.size();
            int ind[n], vis[n];
            memset(ind, 0, sizeof(ind));
            memset(vis, 0, sizeof(vis));
            for (int i = 0; i < n; i++){
                if (edges[i] != -1) ind[edges[i]]++;
            }
            queue<int> q;
            for (int i = 0; i < n; i++){
                if (ind[i] == 0) q.push(i);
            }
            while (q.size()){
                auto temp = q.front();
                q.pop();
                vis[temp] = 1;
                int child = edges[temp];
                if (child == -1) continue;
                if (--ind[child] ==0) q.push(child);
            }
            int yes = 0;
            int ans = 0;
            for (int i = 0; i < n; i++){
                if (vis[i]) continue;
                int count = 0;
                int now = i;
                while (vis[now] == 0){
                    yes = 1;
                    count++;
                    vis[now] = 1;
                    now = edges[now];
                }
                ans = max(ans, count);
            }
            if (yes == 0) return -1;
            return ans;
        
        
    }
};