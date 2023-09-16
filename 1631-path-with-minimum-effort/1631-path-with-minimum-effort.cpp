class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size(), m= heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        
        while(!pq.empty()){
            auto v= pq.top(); pq.pop();
            int x= v[0], y= v[1], d=v[2];
            if(x==n-1 and y==m-1) return d;
            
            for(int i=0; i<4; i++){
                int row= x+ dx[i], col= y+ dy[i];
                if(row>=0 and row<n and col>=0 and col<m){
                    int newDist= max(d, abs(heights[row][col]- heights[x][y]));
                    if(newDist < dist[row][col]){
                        dist[row][col]= newDist;
                        pq.push({row, col, newDist});
                    }
                }
            }
        }
        return 0;
    }
};