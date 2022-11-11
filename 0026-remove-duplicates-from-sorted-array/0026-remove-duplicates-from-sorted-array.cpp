class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int res=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[res]){
                res++;
                nums[res]=nums[i];
            }
        }
        return res+1;
    }
};