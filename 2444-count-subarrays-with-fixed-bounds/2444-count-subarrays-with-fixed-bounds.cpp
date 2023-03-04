class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res=0;
        int j=-1, prevMinIdx=-1, prevMaxIdx=-1, n=nums.size();
        for(int i=0; i<n;i++){
            if(minK > nums[i] or nums[i] > maxK) j=i;
            
            if(nums[i]== minK) prevMinIdx=i;
            if(nums[i]== maxK) prevMaxIdx=i;
            res+= max(0, min(prevMinIdx, prevMaxIdx)-j);
        }
        return res;
    }
};