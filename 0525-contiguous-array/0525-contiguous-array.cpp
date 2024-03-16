class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp{{0, -1}};
        int maxi=0, cnt=0;
        for(int i=0; i<nums.size(); i++){
            cnt += nums[i]==1 ? 1 : -1;
            if(mp.count(cnt)) maxi = max(maxi, i-mp[cnt]);
            else mp[cnt] = i;
        }
        return maxi;
    }
};