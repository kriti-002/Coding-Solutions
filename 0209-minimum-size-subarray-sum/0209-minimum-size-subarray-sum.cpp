class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0, n=nums.size(), res=INT_MAX, sum=0;
        while(j<n){
            sum+=nums[j];
            while(sum >= target){
                res=min(res, j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return res== INT_MAX? 0: res;
    }
};