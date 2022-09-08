class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()<4) return 0;
        int p1= nums[0]*nums[1], p2=nums[nums.size()-2]* nums[nums.size()-1];
        return p2-p1;
    }
};