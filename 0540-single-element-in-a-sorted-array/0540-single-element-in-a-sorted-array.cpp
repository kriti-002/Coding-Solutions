class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0,n=nums.size(), j=n-1;
        if(n==1) return nums[0];
        while(i<=j){
            int mid= i+(j-i)/2;
            if(mid&1){
                if(nums[mid-1]== nums[mid]) i=mid+1;
                else j=mid-1;
            }else{
                if(nums[mid+1]== nums[mid]) i=mid+1;
                else j=mid-1;
            }
        }
        return nums[i];
    }
};