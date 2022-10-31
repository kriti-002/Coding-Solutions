class Solution {
public:
    void help(vector<int>&candidates, vector<vector<int>>&res, int target, int idx, vector<int>&ds){
        int n=candidates.size();
        if(idx==n){
            if(target==0){
               res.push_back(ds); 
            } 
            return;
        }
        if(candidates[idx]<= target){
           ds.push_back(candidates[idx]);
            help(candidates, res, target-candidates[idx], idx, ds);
            ds.pop_back(); 
        }
        help(candidates, res, target, idx+1, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> ds;
        help(candidates,res, target, 0, ds);
        return res;    
    }
};