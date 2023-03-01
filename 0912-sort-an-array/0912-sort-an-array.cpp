class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x: nums) pq.push(x);
        
        vector<int> res;
        while(!pq.empty()){
            auto x= pq.top(); pq.pop();
            res.push_back(x);
        }
        return res;
    }
};