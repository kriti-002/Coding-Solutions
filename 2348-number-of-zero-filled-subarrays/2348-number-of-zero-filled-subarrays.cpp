class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long curr=0, ans=0;
        for(auto &x: nums){
            if(x==0){
                curr++; ans+=curr;
            }else{
                curr=0;
            }
        }
        return ans;
    }
};