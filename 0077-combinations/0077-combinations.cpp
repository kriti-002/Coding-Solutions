class Solution {
    void help(int i, int n, int k, vector<int>&tmp, vector<vector<int>>&res){
        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        
        for(int j=i; j<=n; j++){
            tmp.push_back(j);
            help(j+1,n,k,tmp,res);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int> tmp;
        help(1,n,k,tmp,res);
        return res;
    }
};