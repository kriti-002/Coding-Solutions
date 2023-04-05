class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long presum=0, res=0;
        for(int i=0; i<nums.size(); i++){
            presum+=nums[i];
            res=max(res, (presum+i)/(i+1));
        }
        return (int)res;
    }
};