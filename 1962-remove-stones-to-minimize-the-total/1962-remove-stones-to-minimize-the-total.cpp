class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto &x: piles) pq.push(x);
        
        int ans=0;
        for(int i=0;i<k;i++){
            int x=pq.top(); pq.pop();
            x-=(x/2);   
            pq.push(x);
        }
        while(!pq.empty()){
            ans+=pq.top(); pq.pop();
        }
        return ans;
        
    }
};