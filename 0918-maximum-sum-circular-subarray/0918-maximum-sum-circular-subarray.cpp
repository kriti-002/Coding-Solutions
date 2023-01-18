class Solution {
    int kadaneAlgo(vector<int>& nums){
        int n=nums.size(), curr=nums[0], maxi=nums[0];
        for(int i=1; i<n; i++){
            curr=max(nums[i], curr+nums[i]);
            maxi=max(maxi, curr);
        }
        return maxi;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(), normal=kadaneAlgo(nums);
        if(normal <0) return normal;
        
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            nums[i] = -1 * nums[i];
        }
        int maxCircular = sum + kadaneAlgo(nums);
        return max(normal, maxCircular);
    }
};