class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool monoInc=true, monoDec=true;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]> nums[i]) monoInc=false;
        }
        for(int i=1; i<nums.size();i++){
            if(nums[i-1]<nums[i]) monoDec=false;
        }
        return monoInc or monoDec;
    }
};