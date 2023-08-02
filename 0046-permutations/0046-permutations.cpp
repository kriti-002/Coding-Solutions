class Solution {
    void help(vector<bool>&vis, vector<int>&nums, vector<int>&tmp, vector<vector<int>>&res){
        if(tmp.size()== nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                tmp.push_back(nums[i]);
                vis[i]=1;
                help(vis, nums, tmp, res);
                vis[i]=0;
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        vector<int>tmp;
        vector<bool>vis(n,0);
        help(vis,nums, tmp, res);
        return res;
    }
};