class Solution {
public:
    int mod= 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>vp;
        for(int i=0; i<n; i++){
            vp.push_back({efficiency[i], speed[i]});
        }
        sort(vp.rbegin(), vp.rend());
        priority_queue<int, vector<int>, greater<int>>pq;
        long res=0, tmp=0;
        for(auto x: vp){
            pq.push(x.second);
            tmp+=x.second;
            while(pq.size() >k){
               tmp-=pq.top();
                pq.pop();
            }
            res=max(res, tmp* x.first);
        }
        return res% mod;
    }
};