class Solution {
public:
    vector<char>par;
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        par.resize(26,0);
        if(n<=1) return false;  //can't draw any conclusion
        for(int i=0; i<26; i++){
            par[i]=i;
        }
        for(auto x: equations){
            if(x[1]== '='){
                char a=findRoot(x[0]-'a');
                char b=findRoot(x[3]-'a');
                if(a!=b) par[a]=b;
            }
        }
        for(auto x: equations){
            if(x[1]== '!'){
                char a=findRoot(x[0]-'a');
                char b=findRoot(x[3]-'a');
                if(a==b) return false;
            }
        }
        return true;
        
    }
    char findRoot(char c){
        return par[c]==c ? c:findRoot(par[c]);
    }
};