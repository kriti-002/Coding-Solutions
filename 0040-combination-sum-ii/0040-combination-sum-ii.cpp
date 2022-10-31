class Solution {
public:
    void help(vector<int>& candidates,vector<int>& ds, vector<vector<int>>& res, int idx, int target){
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            if(i> idx and candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            ds.push_back(candidates[i]);
            help(candidates, ds, res, i+1, target-candidates[i]);
            ds.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        help(candidates, ds, res, 0, target);
        return res;
    }
};