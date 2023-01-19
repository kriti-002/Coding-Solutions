class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0, n=nums.size(), sum=0;
        unordered_map<int, int>mp;
        
        for(auto x:nums){
            sum += x;
            mp[(sum%k + k)%k]++;
        }
        count = mp[0];
        
        for(auto x:mp){
            int a = x.second;
            count +=  (a*(a-1))/2;
        }
        
        return count;
    }
};