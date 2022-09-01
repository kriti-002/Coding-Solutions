class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>mp;
        for(auto &x: nums){
            if(mp[x]>0) return x;
            mp[x]++;
        }
        return 0;
    }
};