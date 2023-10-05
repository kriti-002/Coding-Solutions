class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        unordered_map<int, int>m; int n=nums.size();
        for(auto x: nums) m[x]++;
        
        for(auto x: m){
            if(x.second > floor(n/3)) res.push_back(x.first);
        }
        return res;
    }
};