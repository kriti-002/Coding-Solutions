class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> path;
        help(0,s,path, res);
        return res;
    }
    bool isPalin(int i, int j, string& s){
        while(i< j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void help(int idx, string& s,vector<string>&path ,vector<vector<string>>&res){
        int n = s.length();
        if(idx==n){
            res.push_back(path);
        }else{
            for(int j=idx; j<n; j++){
                if(isPalin(idx, j, s)){
                    path.push_back(s.substr(idx, j-idx +1));
                    help(j+1, s,path,res);
                    path.pop_back();
                }
        }
    }
        
    }
};