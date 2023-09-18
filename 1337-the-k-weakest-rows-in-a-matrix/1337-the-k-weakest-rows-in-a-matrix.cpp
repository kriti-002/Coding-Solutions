class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>>s;
        for(int i=0; i<mat.size(); i++){
            int c = count(mat[i].begin(),mat[i].end(),1);
            s.insert({c, i});
        }
        vector<int> res;
        for(auto i: s){
            if(k==0) break;
            res.push_back(i.second);
            k--;
        }
        return res;
    }
};