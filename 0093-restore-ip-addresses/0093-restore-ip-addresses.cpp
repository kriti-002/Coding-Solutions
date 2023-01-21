class Solution {
    bool isValid(string s){
        if(s.size()>3 or s.size()==0) return false;
        if(s.size()>1 and s[0]=='0') return false;
        if(s.size() and stoi(s)>255) return false;
        
        return true;
    }
    void help(int i, int dot, string st, vector<string>&res, string &s){
        if(dot==3){	
            if(isValid(s.substr(i))){
                res.push_back(st+s.substr(i));
            }
        return;
        }
	
        for(int j=i; j<s.size();j++){
            if(isValid(s.substr(i, j-i+1))){
                st.push_back(s[j]);
                st.push_back('.');
                help(j+1, dot+1, st, res, s);
                st.pop_back();
                }
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()<4) return res;
        help(0, 0, "", res, s);
        return res;
        
    }
};