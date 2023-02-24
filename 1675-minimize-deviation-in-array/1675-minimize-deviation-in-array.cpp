class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mini=INT_MAX;
        for(auto x: nums){
            if(x&1){
                pq.push(2*x);
                mini=min(mini, 2*x);
            }
            else{
                pq.push(x);
                mini=min(mini, x);
            }
        }
        int minDev=INT_MAX;
        while(true){
            auto x= pq.top(); pq.pop();
            minDev=min(minDev, x-mini);
            if(x&1) break;
            x/=2;
            mini=min(mini, x);
            pq.push(x);
           
        }
        return minDev;
    }
};