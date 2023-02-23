class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size(),i=0;
        vector<pair<int,int>>pro;
        for(int i=0; i<n; i++) pro.push_back({capital[i],profits[i]});
        
        sort(pro.begin(), pro.end());
        
        priority_queue<int>q;
        
        while(k--){
            while(i< n and pro[i].first<= w){
                q.push(pro[i].second);
                i++;
            }
            if(q.empty()) break;
            auto x= q.top(); q.pop();
            w+=x;
            
        }
        return w;
    }
};