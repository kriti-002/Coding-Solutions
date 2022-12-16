class Solution {
public:
    void help(int idx, vector<int>&tmp, vector<int>&nums, vector<vector<int>>&res){
        res.push_back(tmp);
        for(int j=idx; j<nums.size(); j++){
            tmp.push_back(nums[j]);
            help(j+1, tmp, nums, res);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> tmp;
        help(0, tmp, nums, res);
        return res;
    }
};