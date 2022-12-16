class Solution {
public:
    void help(int i,vector<int>&nums,vector<int>&tmp, vector<vector<int>>&res){
       res.push_back(tmp);
       int n=nums.size();
       for(int j=i; j<n; j++){
           if(j==i or nums[j-1]!= nums[j]){
               tmp.push_back(nums[j]);
               help(j+1, nums, tmp, res);
               tmp.pop_back();
           }
           
       } 
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        help(0,nums, tmp,res);
        return res;
        
    }
};