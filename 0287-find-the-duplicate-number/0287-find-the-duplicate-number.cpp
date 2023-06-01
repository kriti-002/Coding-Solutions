class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool>vis(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(!vis[nums[i]]) vis[nums[i]]=1;
            else return nums[i];
        }
        return -1;
    }
};