class Solution {
public:
    int search(vector<int>& nums, int target) {
       int low=0, high= nums.size()-1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(nums[mid]== target) return mid;
            if(nums[low]<=nums[mid]){
                //lies in this range--> 0 to mid
                if(nums[low]<=target and nums[mid]>target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                //lies in the range --> mid+1 to high
                if(nums[mid+1]<= target and nums[high]>= target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};