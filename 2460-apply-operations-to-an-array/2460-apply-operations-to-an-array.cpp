class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i< nums.size()-1; ++i){
            if(nums[i] == nums[i+1]){  
                nums[i] = 2*nums[i]; 
                nums[i+1] = 0;
            }
        }
        int i = 0;
        for(auto x: nums){ 
            if(x) nums[i++] = x;
        }
        while(i < nums.size()) nums[i++] = 0;
        
        return nums;
    }
};