class Solution {
    int rev(int n){
        int res=0;
        while(n){
            int rem= n%10;
            res= res*10 + rem;
            n/=10;
        }
        return res;
    }
public:
    int mod= 1e9+7;
    int countNicePairs(vector<int>& nums) {
        map<int,int>mp;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            int key= nums[i]- rev(nums[i]);
            if(mp.count(key)){
                count+=mp[key];
                count%=mod;
            }
            mp[key]++;;
        }
        return count;
    }
};