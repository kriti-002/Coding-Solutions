class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int neg=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) return 0;
            if(nums[i]< 0) neg++;
        }
        return !(neg&1) ? 1: -1;
        
    }
};