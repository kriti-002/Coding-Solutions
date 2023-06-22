class Solution {
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k, 0, 0});
        
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        vector<vector<int>> dist(m, vector<int>(n, -1));

        while (!pq.empty()) {
            auto f=pq.top(); pq.pop();
            int steps = f[0], remOb = f[1], x = f[2], y =f[3];

            if (x == m - 1 and y == n - 1) return steps;

            for (int i=0; i<4; i++) {
                int r = x + dx[i], c = y + dy[i];
                if (min(r,c) < 0 or r== m or c == n or g[r][c] < 0) continue;
                int rem = remOb - (g[r][c] == 1);
                if (rem >= 0 and rem > dist[r][c]) {
                    pq.push({steps + 1, rem, r, c});
                    dist[r][c] = rem;
                }
            }
        }
        return -1;
    }
};