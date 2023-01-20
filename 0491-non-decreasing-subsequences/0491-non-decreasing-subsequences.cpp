class Solution {
    vector<vector<int>>res;
    void help(int i, int prevEle, vector<int>&nums, set<vector<int>>&t, vector<int>&tmp){
        if(i== nums.size()) return;
        if(tmp.size() >= 2) t.insert(tmp);
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j] >= prevEle){
                tmp.push_back(nums[j]);
                help(j, nums[j], nums, t, tmp);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>t;
        for(int i=0;i<nums.size();i++){
            vector<int> tmp;
            tmp.push_back(nums[i]);
            help(i,nums[i],nums,t,tmp);
        }
        for(auto s: t){
            res.push_back(s);
        }
        return res;
    }
};