class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>&h, vector<vector<bool>>&vis){
        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true;

        if (i-1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j])
            dfs(i-1, j, h , vis);

        if (i+1 < m && vis[i+1][j] != true && h[i+1][j] >= h[i][j])
            dfs(i+1, j,h, vis);

        if (j-1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j])
            dfs(i, j-1,h, vis);
        
        if (j+1 < n && vis[i][j+1] != true && h[i][j+1] >= h[i][j])
            dfs(i, j+1,h, vis);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            dfs(i, 0,heights, pacific);
            dfs(i, n-1,heights, atlantic);

        }
        
        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
            dfs(m-1, j,heights, atlantic);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) 
                    ans.push_back({i,j});           
            }
        }
        return ans;
    }
};