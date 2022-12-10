class Solution {
public:
    void help(vector<int>&freq, vector<int>&nums, vector<int>&per, vector<vector<int>>&res){
        int n=nums.size(), p=per.size();
        if(p==n){
            res.push_back(per);
            return;
        }
        for(int i=0; i<n; i++){
            if(!freq[i]){
                per.push_back(nums[i]);
                freq[i]=1;
                help(freq, nums, per, res);
                freq[i]=0;
                per.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>per;
        int n=nums.size();
        vector<int>freq(n, 0);
        help(freq, nums, per, res);
        return res;
    }
};